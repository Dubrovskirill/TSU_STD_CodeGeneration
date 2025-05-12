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
    DEFAULT  // Для Java (package-private) и C# (internal)
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
