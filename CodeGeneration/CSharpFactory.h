#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include <memory>
#include "AbstractFactory.h"
#include "CSharpClassUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpPrintOperatorUnit.h"

class CSharpMainUnit : public Unit {
public:
    std::string compile() const override {
        return "class Program {\n    static void Main(string[] args) {\n        MyClass.TestFunc4();\n    }\n}\n";
    }
};

class CSharpFactory : public AbstractFactory {
public:
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override {
        auto unit = std::make_shared<CSharpClassUnit>(name);
        unit->setClassModifiers({"abstract"}); // Устанавливаем abstract по умолчанию
        return unit;
    }

    std::shared_ptr<AbstractMethodUnit> createMethodUnit(
        const std::string& name, const std::string& returnType) const override {
        return std::make_shared<CSharpMethodUnit>("Test" + name, returnType); // Преобразуем в PascalCase
    }

    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const override {
        return std::make_shared<CSharpPrintOperatorUnit>(text);
    }

    std::shared_ptr<Unit> createMainUnit() const override {
        return std::make_shared<CSharpMainUnit>();
    }
};

#endif // CSHARPFACTORY_H
