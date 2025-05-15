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
    virtual void testFunc3() = 0;
protected:
    static void testFunc4() {
    std::cout << "Hello, world!" << std::endl;
        }
private:
    static void testFunc2() {
        }
};
```

### C# код
```csharp
namespace MyNamespace
{
abstract class MyClass
{
    public void TesttestFunc1() {
        }
    abstract public void TesttestFunc3() {
        }
    static protected void TesttestFunc4() {
        Console.WriteLine("Hello, world!");
        }
    static private void TesttestFunc2() {
        }
}
}

class Program {
    static void Main(string[] args) {
        MyClass.TestFunc4();
    }
}
```

### Java код
```java
package mypackage;

abstract class MyClass {
    public void testFunc1() {
        }
    abstract public void testFunc3() {
        }
    static protected void testFunc4() {
        System.out.println("Hello, world!");
        }
    static private void testFunc2() {
        }
}

class Main {
    public static void main(String[] args) {
        MyClass.testFunc4();
    }
}
```

## Сборка проекта

Проект использует QMake и стандарт C++17.

### Требования
- Qt (для сборки с использованием QMake).
- Компилятор, поддерживающий C++17.








