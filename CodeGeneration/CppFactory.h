#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "Unit.h"
#include "AbstractFactory.h"
#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"


class CppFactory : public AbstractFactory {
public:
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override {
        return std::make_shared<CppClassUnit>(name);
    }

    std::shared_ptr<AbstractMethodUnit> createMethodUnit(
        const std::string& name, const std::string& returnType) const override {
        return std::make_shared<CppMethodUnit>(name, returnType);
    }

    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const override {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

#endif // CPPFACTORY_H
