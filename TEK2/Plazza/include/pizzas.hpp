/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef PIZZAS_HPP
    #define PIZZAS_HPP

    #include "base.hpp"

enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaIngredient {
    Dough = 0,
    Tomato = 1,
    Gruyere = 2,
    Ham = 3,
    Mushrooms = 4,
    Steak = 5,
    Eggplant = 6,
    GoatCheese = 7,
    ChiefLove = 8,
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

inline std::map<std::string_view, int> mapPizzaIngredients{
    {"Dough", Dough},
    {"Tomato", Tomato},
    {"Gruyere", Gruyere},
    {"Ham", Ham},
    {"Mushrooms", Mushrooms},
    {"Steak", Steak},
    {"Eggplant", Eggplant},
    {"GoatCheese", GoatCheese},
    {"ChiefLove", ChiefLove},
};

inline std::map<int, std::string_view> revMapPizzaIngredients{
    {Dough, "Dough"},
    {Tomato, "Tomato"},
    {Gruyere, "Gruyere"},
    {Ham, "Ham"},
    {Mushrooms, "Mushrooms"},
    {Steak, "Steak"},
    {Eggplant, "Eggplant"},
    {GoatCheese, "GoatCheese"},
    {ChiefLove, "ChiefLove"},
};

inline std::map<std::string_view, PizzaType> MapPizzaType{
    {"regina", Regina},
    {"margarita", Margarita},
    {"americana", Americana},
    {"fantasia", Fantasia},
};

inline std::map<PizzaType, std::string_view> revMapPizzaType{
    {Regina, "regina"},
    {Margarita, "margarita"},
    {Americana, "americana"},
    {Fantasia, "fantasia"},
};

inline std::map<std::string_view, PizzaSize> MapPizzaSize{
    {"S", S},
    {"M", M},
    {"L", L},
    {"XL", XL},
    {"XXL", XXL},
};

inline std::map<PizzaSize, std::string_view> revMapPizzaSize{
    {S, "S"},
    {M, "M"},
    {L, "L"},
    {XL, "XL"},
    {XXL, "XXL"},
};

class APizza {
public:
    APizza() : _type(Margarita), _size(S), _cookingTime(0) {}
    APizza(PizzaType, PizzaSize);
    virtual ~APizza() = default;

    [[nodiscard]] const PizzaType &getType() const;
    [[nodiscard]] const PizzaSize &getSize() const;
    void setType(PizzaType);
    void setSize(PizzaSize);
    void setCookingTime(double cookingTime, double multiplier);
    static double getCookingTimeFromPizzaType(PizzaType type);
    static std::vector<PizzaIngredient> getIngredientsFromPizzaType(PizzaType type);
    [[nodiscard]] const double &getCookingTime() const;

protected:
    PizzaType _type;
    PizzaSize _size;
    double _cookingTime;
};

class PizzaMargarita : public APizza {
public:
    PizzaMargarita(PizzaSize size, double multiplier);
    PizzaMargarita(PizzaMargarita const &other);
    PizzaMargarita &operator=(PizzaMargarita const &other);
    ~PizzaMargarita() override = default;
};

class PizzaRegina : public APizza {
public:
    PizzaRegina(PizzaSize size, double multiplier);
    PizzaRegina(PizzaRegina const &other);
    PizzaRegina &operator=(PizzaRegina const &other);
    ~PizzaRegina() override = default;
};

class PizzaAmericana : public APizza {
public:
    PizzaAmericana(PizzaSize size, double multiplier);
    PizzaAmericana(PizzaAmericana const &other);
    PizzaAmericana &operator=(PizzaAmericana const &other);
    ~PizzaAmericana() override = default;
};

class PizzaFantasia : public APizza {
public:
    PizzaFantasia(PizzaSize size, double multiplier);
    PizzaFantasia(PizzaFantasia const &other);
    PizzaFantasia &operator=(PizzaFantasia const &other);
    ~PizzaFantasia() override = default;
};

void sendPizza(APizza &pizza, int fd);
APizza receivePizza(int fd);

std::ostream& operator<<(std::ostream& os, const APizza& pizza);
std::istream& operator>>(std::istream& is, APizza& pizza);

#endif //PIZZAS_HPP
