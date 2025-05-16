#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Unit.h"

class JavaClassUnit : public AbstractClassUnit {
public:
    explicit JavaClassUnit(const std::string& name) : m_name(name), m_classModifiers(CLASS_NONE) {
        m_fields.resize(4); // public, protected, private, default
    }

    void setClassModifiers(unsigned int modifiers) override {
        m_classModifiers = modifiers;
    }

    void add(const std::shared_ptr<Unit>& unit, AccessModifier access) override {
        int index;
        switch (access) {
        case PUBLIC: index = 0; break;
        case PROTECTED: index = 1; break;
        case PRIVATE: index = 2; break;
        case DEFAULT: index = 3; break;
        default:
            throw std::runtime_error("Invalid access modifier for Java class.");
        }
        m_fields[index].push_back(unit);
    }

    std::string compile() const override {
        std::string result = "package mypackage;\n\n";
        if (m_classModifiers & CLASS_ABSTRACT) {
            result += "abstract ";
        }
        if (m_classModifiers & CLASS_FINAL) {
            result += "final ";
        }
        result += "class " + m_name + " {\n";
        const std::vector<std::string> accessStrings = {
            "public", "protected", "private", ""
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
        result += "}\n";
        return result;
    }

private:
    std::string m_name;
    unsigned int m_classModifiers;
    std::vector<std::vector<std::shared_ptr<Unit>>> m_fields;
};

// Точка входа для Java
class JavaMainUnit : public Unit {
public:
    std::string compile() const override {
        return "class Main {\n    public static void main(String[] args) {\n        MyClass.testFunc4();\n    }\n}\n";
    }
};

#endif // JAVACLASSUNIT_H
