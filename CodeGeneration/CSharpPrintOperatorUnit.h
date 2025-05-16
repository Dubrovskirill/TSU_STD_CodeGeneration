#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Unit.h"

class CSharpPrintOperatorUnit : public AbstractPrintOperatorUnit {
public:
    explicit CSharpPrintOperatorUnit(const std::string& text) : m_text(text) {}

    std::string compile() const override {
        return "Console.WriteLine(\"" + m_text + "\");\n";
    }

private:
    std::string m_text;
};

#endif // CSHARPPRINTOPERATORUNIT_H
