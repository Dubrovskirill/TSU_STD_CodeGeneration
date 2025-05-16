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
    method1->setModifiers(METHOD_NONE);
    myClass->add(method1, PUBLIC);

    // Метод 2: private, static
    auto method2 = factory.createMethodUnit("testFunc2", "void");
    method2->setModifiers(METHOD_STATIC);
    myClass->add(method2, PRIVATE);

    // Метод 3: public, abstract
    auto method3 = factory.createMethodUnit("testFunc3", "void");
    method3->setModifiers(METHOD_ABSTRACT);
    myClass->add(method3, PUBLIC);

    // Метод 4: protected, static, с выводом текста
    auto method4 = factory.createMethodUnit("testFunc4", "void");
    method4->setModifiers(METHOD_STATIC);
    auto printOp = factory.createPrintOperatorUnit("Hello, world!");
    method4->add(printOp);
    myClass->add(method4, PROTECTED);

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
