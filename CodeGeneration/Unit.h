#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include <memory>

// Базовый класс для всех конструкций
class Unit {
public:
    virtual std::string compile() const = 0;
    virtual ~Unit() = default;
};

// Перечисление для модификаторов доступа
enum AccessModifier {
    PUBLIC,
    PROTECTED,
    PRIVATE,
    DEFAULT,  // Для Java (package-private)
    INTERNAL  // Для C# (internal)
};

// Перечисление для модификаторов классов
enum ClassModifier {
    NONE = 0,
    ABSTRACT = 1,
    FINAL = 2,    // Java: final, C#: sealed
    STATIC = 4    // C#: static
};

// Перечисление для модификаторов методов
enum MethodModifier {
    METHOD_NONE = 0,
    METHOD_STATIC = 1,
    METHOD_ABSTRACT = 2,
    METHOD_VIRTUAL = 4,
    METHOD_OVERRIDE = 8, // C# only
    METHOD_FINAL = 16,   // Java: final, C#: sealed
    METHOD_CONST = 32    // C++ only
};


class AbstractClassUnit : public Unit {
public:
    virtual void setClassModifiers(const std::vector<std::string>& modifiers) = 0;
    virtual void add(const std::shared_ptr<Unit>& unit, AccessModifier access) = 0;
};


class AbstractMethodUnit : public Unit {
public:
    virtual void setModifiers(const std::vector<std::string>& modifiers) = 0;
    virtual void add(const std::shared_ptr<Unit>& unit) = 0;
};


class AbstractPrintOperatorUnit : public Unit {
};


#endif // UNIT_H
