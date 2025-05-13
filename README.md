# TSU_STD_CodeGeneration
![UML фабрика](https://github.com/user-attachments/assets/d8aa7bd4-3c00-4ac0-a372-1eb8c7510b69)
CodeGenerator
Описание проекта
CodeGenerator — это программа на C++, которая генерирует код на языках C++, C# и Java с использованием паттерна "Абстрактная фабрика". Она позволяет создавать классы, методы и операторы печати, учитывая специфические модификаторы и синтаксис каждого языка. Программа разработана для демонстрации расширяемости генерации кода и поддержки различных языков программирования.

UML-схема
Ниже представлена UML-схема классов программы, созданная с использованием синтаксиса Mermaid. Вы можете визуализировать её в инструментах, поддерживающих Mermaid (например, в GitHub или с помощью плагинов в редакторах).
classDiagram
    class Unit {
        +compile(level: unsigned int) string
        #generateShift(level: unsigned int) string
    }

    class ClassUnit {
        <<abstract>>
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class MethodUnit {
        <<abstract>>
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class PrintOperatorUnit {
        <<abstract>>
    }

    class iFactory {
        <<interface>>
        +makeClass(name: string) shared_ptr<ClassUnit>
        +makeMethod(name: string, returnType: string, flags: Flags) shared_ptr<MethodUnit>
        +makePrintOperator(text: string) shared_ptr<PrintOperatorUnit>
    }

    class CppFactory {
        +makeClass(name: string) shared_ptr<ClassUnit>
        +makeMethod(name: string, returnType: string, flags: Flags) shared_ptr<MethodUnit>
        +makePrintOperator(text: string) shared_ptr<PrintOperatorUnit>
    }

    class CSharpFactory {
        +makeClass(name: string) shared_ptr<ClassUnit>
        +makeMethod(name: string, returnType: string, flags: Flags) shared_ptr<MethodUnit>
        +makePrintOperator(text: string) shared_ptr<PrintOperatorUnit>
    }

    class JavaFactory {
        +makeClass(name: string) shared_ptr<ClassUnit>
        +makeMethod(name: string, returnType: string, flags: Flags) shared_ptr<MethodUnit>
        +makePrintOperator(text: string) shared_ptr<PrintOperatorUnit>
    }

    class CppClassUnit {
        +compile(level: unsigned int) string
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class CSharpClassUnit {
        +compile(level: unsigned int) string
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class JavaClassUnit {
        +compile(level: unsigned int) string
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class CppMethodUnit {
        +compile(level: unsigned int) string
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class CSharpMethodUnit {
        +compile(level: unsigned int) string
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class JavaMethodUnit {
        +compile(level: unsigned int) string
        +add(unit: shared_ptr<Unit>, flags: Flags) void
    }

    class CppPrintOperatorUnit {
        +compile(level: unsigned int) string
    }

    class CSharpPrintOperatorUnit {
        +compile(level: unsigned int) string
    }

    class JavaPrintOperatorUnit {
        +compile(level: unsigned int) string
    }

    Unit <|-- ClassUnit
    Unit <|-- MethodUnit
    Unit <|-- PrintOperatorUnit
    ClassUnit <|-- CppClassUnit
    ClassUnit <|-- CSharpClassUnit
    ClassUnit <|-- JavaClassUnit
    MethodUnit <|-- CppMethodUnit
    MethodUnit <|-- CSharpMethodUnit
    MethodUnit <|-- JavaMethodUnit
    PrintOperatorUnit <|-- CppPrintOperatorUnit
    PrintOperatorUnit <|-- CSharpPrintOperatorUnit
    PrintOperatorUnit <|-- JavaPrintOperatorUnit
    iFactory <|.. CppFactory
    iFactory <|.. CSharpFactory
    iFactory <|.. JavaFactory


Примеры использования
Программа генерирует код для класса MyClass с четырьмя методами (testFunc1, testFunc2, testFunc3, testFunc4) на трех языках программирования. Пример вывода:
C++ код:
class MyClass {
    public:
        void testFunc1() {
        }
        virtual void testFunc3() {
        }
    protected:
        static void testFunc4() {
            printf("Hello, world!\n");
        }
    private:
        static void testFunc2() {
        }
};

C# код:
public class MyClass {
    public void testFunc1() {
    }
    public virtual void testFunc3() {
    }
    protected static void testFunc4() {
        Console.WriteLine("Hello, world!");
    }
    private static void testFunc2() {
    }
}

Java код:
public class MyClass {
    public void testFunc1() {
    }
    public void testFunc3() {
    }
    protected static void testFunc4() {
        System.out.println("Hello, world!");
    }
    private static void testFunc2() {
    }
}


Структура проекта

main.cpp — Точка входа программы, содержит функцию main и generateProgram.
Unit.h — Определение базового класса Unit.
ClassUnit.h — Определение абстрактного класса ClassUnit.
MethodUnit.h — Определение абстрактного класса MethodUnit.
PrintOperatorUnit.h — Определение абстрактного класса PrintOperatorUnit.
iFactory.h — Определение интерфейса фабрики iFactory.
CppFactory.h — Реализация фабрики для C++.
CSharpFactory.h — Реализация фабрики для C#.
JavaFactory.h — Реализация фабрики для Java.
CppClassUnit.h, CppMethodUnit.h, CppPrintOperatorUnit.h — Классы для генерации C++ кода.
CSharpClassUnit.h, CSharpMethodUnit.h, CSharpPrintOperatorUnit.h — Классы для генерации C# кода.
JavaClassUnit.h, JavaMethodUnit.h, JavaPrintOperatorUnit.h — Классы для генерации Java кода.



