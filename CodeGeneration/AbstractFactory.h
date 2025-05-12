#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "Unit.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const = 0;
    virtual std::shared_ptr<AbstractMethodUnit> createMethodUnit(
        const std::string& name, const std::string& returnType) const = 0;
    virtual std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const = 0;
    virtual ~AbstractFactory() = default;
};

#endif // ABSTRACTFACTORY_H
