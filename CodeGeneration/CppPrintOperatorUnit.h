#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "Unit.h"

class CppPrintOperatorUnit : public AbstractPrintOperatorUnit {
public:
    explicit CppPrintOperatorUnit(const std::string& text) : m_text(text) {}

    std::string compile() const override {
        return "std::cout << \"" + m_text + "\" << std::endl;\n";
    }

private:
    std::string m_text;
};

#endif // CPPPRINTOPERATORUNIT_H
