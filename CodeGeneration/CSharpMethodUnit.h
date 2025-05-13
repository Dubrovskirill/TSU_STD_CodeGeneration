#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Unit.h"

class CSharpMethodUnit : public AbstractMethodUnit {
public:
    CSharpMethodUnit(const std::string& name, const std::string& returnType)
        : m_name(name), m_returnType(returnType) {}

    void setModifiers(const std::vector<std::string>& modifiers) override {
        m_modifiers = modifiers;
    }

    void add(const std::shared_ptr<Unit>& unit) override {
        m_body.push_back(unit);
    }

    std::string compile() const override {
        std::string result;
        for (const auto& mod : m_modifiers) {
            if (mod == "static" || mod == "virtual" || mod == "abstract" || mod == "override" || mod == "sealed") {
                result += mod + " ";
            }
        }
        result += m_returnType + " " + m_name + "()" + " {\n";
        for (const auto& unit : m_body) {
            result += unit->compile();
        }
        result += "    }\n";
        return result;
    }

private:
    std::string m_name;
    std::string m_returnType;
    std::vector<std::string> m_modifiers;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // CSHARPMETHODUNIT_H
