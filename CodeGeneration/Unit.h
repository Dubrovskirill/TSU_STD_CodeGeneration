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
    DEFAULT,
    INTERNAL
};

// Перечисление для модификаторов классов
enum ClassModifier {
    CLASS_NONE = 0,
    CLASS_ABSTRACT = 1 << 0,
    CLASS_FINAL = 1 << 1,
    CLASS_STATIC = 1 << 2
};

// Перечисление для модификаторов методов
enum MethodModifier {
    METHOD_NONE = 0,
    METHOD_STATIC = 1 << 0,
    METHOD_ABSTRACT = 1 << 1,
    METHOD_VIRTUAL = 1 << 2,
    METHOD_CONST = 1 << 3,
    METHOD_FINAL = 1 << 4,
    METHOD_OVERRIDE = 1 << 5
};




class AbstractClassUnit : public Unit {
public:
    virtual void setClassModifiers(unsigned int modifiers) = 0;
    virtual void add(const std::shared_ptr<Unit>& unit, AccessModifier access) = 0;
};

class AbstractMethodUnit : public Unit {
public:
    virtual void setModifiers(unsigned int modifiers) = 0;
    virtual void add(const std::shared_ptr<Unit>& unit) = 0;
};

class AbstractPrintOperatorUnit : public Unit {};


#endif // UNIT_H
