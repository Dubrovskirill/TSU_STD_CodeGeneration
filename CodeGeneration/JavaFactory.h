#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include <memory>
#include "AbstractFactory.h"
#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

class JavaFactory : public AbstractFactory {
public:
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override {
        return std::make_shared<JavaClassUnit>(name);
    }

    std::shared_ptr<AbstractMethodUnit> createMethodUnit(
        const std::string& name, const std::string& returnType) const override {
        return std::make_shared<JavaMethodUnit>(name, returnType);
    }

    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};

#endif // JAVAFACTORY_H
