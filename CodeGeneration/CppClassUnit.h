#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "Unit.h"

class CppClassUnit : public AbstractClassUnit {
public:
    explicit CppClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize(3);  // public, protected, private
    }

    void setClassModifiers(const std::vector<std::string>& /*modifiers*/) override {
        std::cerr << "Warning: Class modifiers are not supported in C++." << std::endl;
    }

    void add(const std::shared_ptr<Unit>& unit, AccessModifier access) override {
        int index;
        switch (access) {
        case AccessModifier::PUBLIC: index = 0; break;
        case AccessModifier::PROTECTED: index = 1; break;
        case AccessModifier::PRIVATE: index = 2; break;
        default:
            throw std::runtime_error("Invalid access modifier for C++ class.");
        }
        m_fields[index].push_back(unit);
    }

    std::string compile() const override {
        std::string result = "class " + m_name + " {\n";
        const std::vector<std::string> accessStrings = {"public:", "protected:", "private:"};
        for (size_t i = 0; i < m_fields.size(); ++i) {
            if (!m_fields[i].empty()) {
                result += "    " + accessStrings[i] + "\n";
                for (const auto& unit : m_fields[i]) {
                    std::string unitCode = unit->compile();
                    // Добавляем отступы для вложенного кода
                    std::string indentedCode;
                    size_t pos = 0;
                    while (pos < unitCode.length()) {
                        size_t nextPos = unitCode.find('\n', pos);
                        if (nextPos == std::string::npos) {
                            indentedCode += "        " + unitCode.substr(pos) + "\n";
                            break;
                        }
                        indentedCode += "        " + unitCode.substr(pos, nextPos - pos) + "\n";
                        pos = nextPos + 1;
                    }
                    result += indentedCode;
                }
            }
        }
        result += "};\n";
        return result;
    }

private:
    std::string m_name;
    std::vector<std::vector<std::shared_ptr<Unit>>> m_fields;
};


#endif // CPPCLASSUNIT_H
