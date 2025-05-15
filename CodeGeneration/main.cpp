#include <QCoreApplication>
#include <iostream>
#include <memory>
#include "Unit.h"
#include "AbstractFactory.h"
#include "CppFactory.h"
#include "CSharpFactory.h"
#include "JavaFactory.h"

std::string generateProgram(const AbstractFactory& factory) {
    auto myClass = factory.createClassUnit("MyClass");

    // Метод 1: public, без модификаторов
    auto method1 = factory.createMethodUnit("testFunc1", "void");
    method1->setModifiers({});
    myClass->add(method1, AccessModifier::PUBLIC);

    // Метод 2: private, static
    auto method2 = factory.createMethodUnit("testFunc2", "void");
    method2->setModifiers({"static"});
    myClass->add(method2, AccessModifier::PRIVATE);

    // Метод 3: public, virtual/abstract
    auto method3 = factory.createMethodUnit("testFunc3", "void");
    method3->setModifiers({"abstract"}); // Фабрика сама определит, использовать abstract или virtual
    myClass->add(method3, AccessModifier::PUBLIC);

    // Метод 4: protected, static, с выводом текста
    auto method4 = factory.createMethodUnit("testFunc4", "void");
    method4->setModifiers({"static", "public"});
    auto printOp = factory.createPrintOperatorUnit("Hello, world!");
    method4->add(printOp);
    myClass->add(method4, AccessModifier::PROTECTED);

    std::string result = myClass->compile();

    // Добавляем точку входа, если фабрика ее предоставляет
    auto mainUnit = factory.createMainUnit();
    if (mainUnit) {
        result += "\n" + mainUnit->compile();
    }

    return result;
}

int main() {
    std::cout << "C++ Code:\n" << std::string(40, '-') << "\n";
    CppFactory cppFactory;
    std::cout << generateProgram(cppFactory) << "\n";

    std::cout << "C# Code:\n" << std::string(40, '-') << "\n";
    CSharpFactory csharpFactory;
    std::cout << generateProgram(csharpFactory) << "\n";

    std::cout << "Java Code:\n" << std::string(40, '-') << "\n";
    JavaFactory javaFactory;
    std::cout << generateProgram(javaFactory) << "\n";

    return 0;
}
