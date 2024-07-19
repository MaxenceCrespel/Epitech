/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/pizzas.hpp"

APizza::APizza(PizzaType type, PizzaSize size)
    : _type(type),
      _size(size),
      _cookingTime(0)
{
}

const PizzaType &APizza::getType() const
{
    return _type;
}

const PizzaSize &APizza::getSize() const
{
    return _size;
}

const double &APizza::getCookingTime() const
{
    return _cookingTime;
}

PizzaMargarita::PizzaMargarita(PizzaSize size, double multiplier)
    : APizza(Margarita, size)
{
    _cookingTime = 1 * multiplier;
}

PizzaMargarita::PizzaMargarita(PizzaMargarita const &other)
    : APizza(other._type, other._size)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
}

PizzaMargarita &PizzaMargarita::operator=(PizzaMargarita const &other)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
    return *this;
}

PizzaRegina::PizzaRegina(PizzaSize size, double multiplier)
    : APizza(Regina, size)
{
    _cookingTime = 2 * multiplier;
}

PizzaRegina::PizzaRegina(PizzaRegina const &other)
    : APizza(other._type, other._size)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
}

PizzaRegina &PizzaRegina::operator=(PizzaRegina const &other)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
    return *this;
}

PizzaAmericana::PizzaAmericana(PizzaSize size, double multiplier)
    : APizza(Americana, size)
{
    _cookingTime = 2 * multiplier;
}

PizzaAmericana::PizzaAmericana(PizzaAmericana const &other)
    : APizza(other._type, other._size)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
}

PizzaAmericana &PizzaAmericana::operator=(PizzaAmericana const &other)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
    return *this;
}

PizzaFantasia::PizzaFantasia(PizzaSize size, double multiplier)
    : APizza(Fantasia, size)
{
    _cookingTime = 4 * multiplier;
}

PizzaFantasia::PizzaFantasia(PizzaFantasia const &other)
    : APizza(other._type, other._size)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
}

PizzaFantasia &PizzaFantasia::operator=(PizzaFantasia const &other)
{
    _type = other._type;
    _size = other._size;
    _cookingTime = other._cookingTime;
    return *this;
}

void APizza::setType(PizzaType a)
{
    _type = a;
}

void APizza::setSize(PizzaSize a)
{
    _size = a;
}

void APizza::setCookingTime(double cookingTime, double multiplier)
{
    _cookingTime = cookingTime * multiplier;
}

double APizza::getCookingTimeFromPizzaType(PizzaType type)
{
    switch (type) {
    case Margarita:
        return 1;
    case Regina:
        return 2;
    case Americana:
        return 2;
    case Fantasia:
        return 4;
    default:
        return 0;
    }
}

std::vector<PizzaIngredient> APizza::getIngredientsFromPizzaType(PizzaType type)
{
    switch (type) {
    case Margarita:
        return {Dough, Tomato, Gruyere};
    case Regina:
        return {Dough, Tomato, Gruyere, Ham, Mushrooms};
    case Americana:
        return {Dough, Tomato, Gruyere, Steak};
    case Fantasia:
        return {Dough, Tomato, Eggplant, GoatCheese, ChiefLove};
    default:
        return {};
    }
}

std::ostream &operator<<(std::ostream &os, const APizza &pizza)
{
    os << static_cast<int>(pizza.getType()) << " " << std::setw(2) << std::setfill('0') <<
        static_cast<int>(pizza.getSize());
    return os;
}

std::istream &operator>>(std::istream &is, APizza &pizza)
{
    int type, size;
    is >> type >> size;
    pizza.setType(static_cast<PizzaType>(type));
    pizza.setSize(static_cast<PizzaSize>(size));
    return is;
}

void sendPizza(APizza &pizza, int fd)
{
    std::stringstream str;

    str << 1 << pizza;
    write(fd, str.str().c_str(), str.str().size());
}

APizza receivePizza(int fd)
{
    char buff[256];
    std::stringstream ss;
    APizza pizza;

    memset(buff, 0, 256);
    size_t size = read(fd, buff, 4);
    if (size == 0)
        return pizza;
    std::string str(buff, size);
    ss << str;
    ss >> pizza;
    return pizza;
}
