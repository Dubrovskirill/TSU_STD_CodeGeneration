#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Unit.h"

class JavaMethodUnit : public AbstractMethodUnit {
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType)
        : m_name(name), m_returnType(returnType), m_modifiers(METHOD_NONE) {}

    void setModifiers(unsigned int modifiers) override {
        m_modifiers = modifiers;
    }

    void add(const std::shared_ptr<Unit>& unit) override {
        m_body.push_back(unit);
    }

    std::string compile() const override {
        std::string result;
        if (m_modifiers & METHOD_STATIC) {
            result += "static ";
        }
        if (m_modifiers & METHOD_ABSTRACT) {
            result += "abstract ";
        }
        if (m_modifiers & METHOD_FINAL) {
            result += "final ";
        }
        result += m_returnType + " " + m_name + "()";
        if (m_modifiers & METHOD_ABSTRACT) {
            result += ";\n";
        } else {
            result += " {\n";
            for (const auto& unit : m_body) {
                result += "    " + unit->compile();
            }
            result += "    }\n";
        }
        return result;
    }

private:
    std::string m_name;
    std::string m_returnType;
    unsigned int m_modifiers;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // JAVAMETHODUNIT_H
