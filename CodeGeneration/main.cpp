#include <QCoreApplication>
#include <iostream>
#include <memory>
#include "Unit.h"
#include "AbstractFactory.h"
#include "CppFactory.h"
#include "CSharpFactory.h"

std::string generateProgram(const AbstractFactory& factory, const std::string& language) {
    auto myClass = factory.createClassUnit("MyClass");

    // Устанавливаем модификаторы класса только для C#
    if (language == "C#") {
        myClass->setClassModifiers({"abstract"});
    }

    // Имена методов в зависимости от языка
    std::string method1Name = (language == "C#") ? "TestFunc1" : "testFunc1";
    std::string method2Name = (language == "C#") ? "TestFunc2" : "testFunc2";
    std::string method3Name = (language == "C#") ? "TestFunc3" : "testFunc3";
    std::string method4Name = (language == "C#") ? "TestFunc4" : "testFunc4";

    // Метод 1: public, без модификаторов
    auto method1 = factory.createMethodUnit(method1Name, "void");
    method1->setModifiers({});
    myClass->add(method1, PUBLIC);

    // Метод 2: private, static
    auto method2 = factory.createMethodUnit(method2Name, "void");
    method2->setModifiers({"static"});
    myClass->add(method2, PRIVATE);

    // Метод 3: public, virtual (C++) или abstract (C#)
    auto method3 = factory.createMethodUnit(method3Name, "void");
    if (language == "C++") {
        method3->setModifiers({"virtual", "const"});
    } else {
        method3->setModifiers({"abstract"});
    }
    myClass->add(method3, PUBLIC);

    // Метод 4: protected, static, с выводом текста
    auto method4 = factory.createMethodUnit(method4Name, "void");
    method4->setModifiers({"static"});
    auto printOp = factory.createPrintOperatorUnit("Hello, world!");
    method4->add(printOp);
    myClass->add(method4, PROTECTED);

    // Добавляем точку входа для C#
    std::string result = myClass->compile();
    if (language == "C#") {
        result += "\nclass Program {\n    static void Main(string[] args) {\n";
        result += "        MyClass.TestFunc4();\n    }\n}\n";
    }
    return result;
}

int main() {
    std::cout << "C++ Code:\n" << std::string(40, '-') << "\n";
    CppFactory cppFactory;
    std::cout << generateProgram(cppFactory, "C++") << "\n";

    std::cout << "C# Code:\n" << std::string(40, '-') << "\n";
    CSharpFactory csharpFactory;
    std::cout << generateProgram(csharpFactory, "C#") << "\n";

    return 0;
}
