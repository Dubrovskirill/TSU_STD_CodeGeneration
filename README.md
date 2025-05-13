# TSU_STD_CodeGeneration 

## Описание 

CodeGenerator — это программа на C++, которая генерирует код на языках C++, C# и Java с использованием паттерна "Абстрактная фабрика". Она позволяет создавать классы, методы и операторы печати, учитывая специфические модификаторы и синтаксис каждого языка. Программа разработана для демонстрации расширяемости генерации кода и поддержки различных языков программирования.

## UML-схема

![UML фабрика](https://github.com/user-attachments/assets/d8aa7bd4-3c00-4ac0-a372-1eb8c7510b69)

## Примеры использования

Программа генерирует код для класса `MyClass` с четырьмя методами (`testFunc1`, `testFunc2`, `testFunc3`, `testFunc4`) на трех языках программирования. Примеры вывода:

### C++ код
```cpp
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
```

### C# код
```csharp
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
```

### Java код
```java
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
```

## Структура проекта

- `main.cpp` — Точка входа программы, содержит функции `main` и `generateProgram`.
- `Unit.h` — Определение базового класса `Unit`.
- `ClassUnit.h` — Определение абстрактного класса `ClassUnit`.
- `MethodUnit.h` — Определение абстрактного класса `MethodUnit`.
- `PrintOperatorUnit.h` — Определение абстрактного класса `PrintOperatorUnit`.
- `iFactory.h` — Определение интерфейса фабрики `iFactory`.
- `CppFactory.h` — Реализация фабрики для C++.
- `CSharpFactory.h` — Реализация фабрики для C#.
- `JavaFactory.h` — Реализация фабрики для Java.
- `CppClassUnit.h`, `CppMethodUnit.h`, `CppPrintOperatorUnit.h` — Классы для генерации C++ кода.
- `CSharpClassUnit.h`, `CSharpMethodUnit.h`, `CSharpPrintOperatorUnit.h` — Классы для генерации C# кода.
- `JavaClassUnit.h`, `JavaMethodUnit.h`, `JavaPrintOperatorUnit.h` — Классы для генерации Java кода.

## Сборка проекта

Проект использует QMake и стандарт C++17.

### Требования
- Qt (для сборки с использованием QMake).
- Компилятор, поддерживающий C++17.








