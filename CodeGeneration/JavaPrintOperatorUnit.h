#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Unit.h"

class JavaPrintOperatorUnit : public AbstractPrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text) : m_text(text) {}

    std::string compile() const override {
        return "    System.out.println(\"" + m_text + "\");\n";
    }

private:
    std::string m_text;
};

#endif // JAVAPRINTOPERATORUNIT_H
