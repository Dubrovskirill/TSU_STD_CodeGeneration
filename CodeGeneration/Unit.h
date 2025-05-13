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
enum class AccessModifier {
    PUBLIC,
    PROTECTED,
    PRIVATE,
    DEFAULT,
    INTERNAL
};

// Перечисление для модификаторов классов
enum class ClassModifier {
    NONE,
    ABSTRACT,
    FINAL,
    STATIC
};

// Перечисление для модификаторов методов
enum class MethodModifier {
    NONE,
    STATIC,
    ABSTRACT,
    VIRTUAL,
    OVERRIDE,
    FINAL,
    CONST
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
