
#include <QCoreApplication>
#include <iostream>

#include "Unit.h"
#include "AbstractFactory.h"
#include "CppFactory.h"

std::string generateProgram(const AbstractFactory& factory) {
    auto myClass = factory.createClassUnit("MyClass");

    auto method1 = factory.createMethodUnit("testFunc1", "void");
    method1->setModifiers({});
    myClass->add(method1, PUBLIC);

    auto method2 = factory.createMethodUnit("testFunc2", "void");
    method2->setModifiers({"static"});
    myClass->add(method2, PRIVATE);

    auto method3 = factory.createMethodUnit("testFunc3", "void");
    method3->setModifiers({"virtual", "const"});
    myClass->add(method3, PUBLIC);

    auto method4 = factory.createMethodUnit("testFunc4", "void");
    method4->setModifiers({"static"});
    auto printOp = factory.createPrintOperatorUnit("Hello, world!");
    method4->add(printOp);
    myClass->add(method4, PROTECTED);

    return myClass->compile();
}

int main() {
    CppFactory factory;
    std::cout << generateProgram(factory) << std::endl;
    return 0;
}
