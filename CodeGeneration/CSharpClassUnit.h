#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Unit.h"

class CSharpClassUnit : public AbstractClassUnit {
public:
    explicit CSharpClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize(5); // public, protected, private, default, internal
    }

    void setClassModifiers(const std::vector<std::string>& modifiers) override {
        m_classModifiers = modifiers;
    }

    void add(const std::shared_ptr<Unit>& unit, AccessModifier access) override {
        int index;
        switch (access) {
        case AccessModifier::PUBLIC: index = 0; break;
        case AccessModifier::PROTECTED: index = 1; break;
        case AccessModifier::PRIVATE: index = 2; break;
        case AccessModifier::DEFAULT: index = 3; break;
        case AccessModifier::INTERNAL: index = 4; break;
        default:
            throw std::runtime_error("Invalid access modifier for C# class.");
        }
        m_fields[index].push_back(unit);
    }

    std::string compile() const override {
        std::string result = "namespace MyNamespace\n{\n";
        for (const auto& mod : m_classModifiers) {
            if (mod == "abstract" || mod == "sealed" || mod == "static") {
                result += mod + " ";
            }
        }
        result += "class " + m_name + "\n{\n";
        const std::vector<std::string> accessStrings = {
            "public", "protected", "private", "", "internal"
        };
        for (size_t i = 0; i < m_fields.size(); ++i) {
            if (!m_fields[i].empty()) {
                for (const auto& unit : m_fields[i]) {
                    std::string unitCode = unit->compile();
                    std::string indentedCode;
                    size_t pos = 0;
                    while (pos < unitCode.length()) {
                        size_t nextPos = unitCode.find('\n', pos);
                        if (nextPos == std::string::npos) {
                            indentedCode += "    " + unitCode.substr(pos);
                            break;
                        }
                        indentedCode += "    " + unitCode.substr(pos, nextPos - pos) + "\n";
                        pos = nextPos + 1;
                    }
                    std::string prefix = (i != 3) ? accessStrings[i] + " " : "";
                    size_t methodStart = unitCode.find("void");
                    if (methodStart != std::string::npos) {
                        indentedCode.insert(indentedCode.find("void"), prefix);
                    }
                    result += indentedCode;
                }
            }
        }
        result += "}\n}\n";
        return result;
    }

private:
    std::string m_name;
    std::vector<std::string> m_classModifiers;
    std::vector<std::vector<std::shared_ptr<Unit>>> m_fields;
};

#endif // CSHARPCLASSUNIT_H
