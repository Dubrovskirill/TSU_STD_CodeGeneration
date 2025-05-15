#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "Unit.h"

class CppMethodUnit : public AbstractMethodUnit {
public:
    CppMethodUnit(const std::string& name, const std::string& returnType)
        : m_name(name), m_returnType(returnType) {}

    void setModifiers(const std::vector<std::string>& modifiers) override {
        m_modifiers.clear();
        for (const auto& mod : modifiers) {
            if (mod == "abstract") {
                m_modifiers.push_back("virtual"); // abstract в C++ преобразуем в virtual
            } else if (mod == "static" || mod == "virtual" || mod == "const") {
                m_modifiers.push_back(mod);
            }
        }
    }

    void add(const std::shared_ptr<Unit>& unit) override {
        m_body.push_back(unit);
    }

    std::string compile() const override {
        std::string result;
        bool isAbstract = std::find(m_modifiers.begin(), m_modifiers.end(), "virtual") != m_modifiers.end();
        for (const auto& mod : m_modifiers) {
            if (mod == "static" || mod == "virtual") {
                result += mod + " ";
            }
        }
        result += m_returnType + " " + m_name + "()";
        if (std::find(m_modifiers.begin(), m_modifiers.end(), "const") != m_modifiers.end()) {
            result += " const";
        }
        if (isAbstract) {
            result += " = 0;";
        } else {
            result += " {\n";
            for (const auto& unit : m_body) {
                result += unit->compile();
            }
            result += "    }\n";
        }
        return result;
    }

private:
    std::string m_name;
    std::string m_returnType;
    std::vector<std::string> m_modifiers;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // CPPMETHODUNIT_H
