#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "Unit.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<AbstractMethodUnit> createMethodUnit(
        const std::string& name, const std::string& returnType) = 0;
    virtual std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) = 0;
    virtual ~AbstractFactory() = default;
};

#endif // ABSTRACTFACTORY_H
