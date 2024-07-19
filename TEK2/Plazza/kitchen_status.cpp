/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/kitchen_status.hpp"

Status::Status(std::vector<bool> cookIsCooking, std::map<PizzaIngredient, size_t> _ingredients)
    : _cookIsCooking(std::move(cookIsCooking)),
      _ingredients(std::move(_ingredients))
{
}

Status::Status()
    : _cookIsCooking(), _ingredients()
{
}

Status::~Status()
{
}

void Status::printStatus()
{
    std::stringstream ss;

    ss << "COOKS:" << std::endl;
    for (size_t i = 0; i < _cookIsCooking.size(); i++) {
        if (_cookIsCooking[i])
            ss << "  [" << i << "] is cooking" << std::endl;
        else
            ss << "  [" << i << "] is not cooking" << std::endl;
    }

    ss << "INGREDIENTS:" << std::endl;
    for (int i = 0; i < 8; i++)
        ss << "  " << revMapPizzaIngredients[static_cast<PizzaIngredient>(i)] << ": ["
            << _ingredients[static_cast<PizzaIngredient>(i)] << "]" << std::endl;

    std::string str = ss.str();
    std::cout << str;
    appendToLogFile(str);
}

std::vector<bool> Status::getCookIsCooking() const
{
    return _cookIsCooking;
}

void Status::setCookIsCooking(std::vector<bool> cookIsCooking)
{
    _cookIsCooking = std::move(cookIsCooking);
}

std::map<PizzaIngredient, size_t> Status::getIngredients() const
{
    return _ingredients;
}

void Status::setIngredients(std::map<PizzaIngredient, size_t> ingredients)
{
    _ingredients = std::move(ingredients);
}

std::ostream &operator<<(std::ostream &os, const Status &status)
{
    std::vector<bool> cookIsCooking = status.getCookIsCooking();
    std::map<PizzaIngredient, size_t> ingredients = status.getIngredients();

    if (cookIsCooking.empty())
        throw StatusException("CookIsCooking is empty");

    size_t cooksNb = cookIsCooking.size();

    os << std::setw(8) << std::setfill('0') << cooksNb << " " << cookIsCooking[0];
    for (size_t i = 1; i < cooksNb; i++)
        os << " " << cookIsCooking[i];

    for (int i = 0; i < 8; i++)
        os << " " << std::setw(8) << std::setfill('0') << ingredients[static_cast<PizzaIngredient>(i)];
    return os;
}

std::istream &operator>>(std::istream &is, Status &status)
{
    size_t cooksNb;
    std::vector<bool> cookIsCooking;
    std::map<PizzaIngredient, size_t> ingredients;

    ingredients.insert(std::make_pair(Dough, 0));
    ingredients.insert(std::make_pair(Tomato, 0));
    ingredients.insert(std::make_pair(Gruyere, 0));
    ingredients.insert(std::make_pair(Ham, 0));
    ingredients.insert(std::make_pair(Mushrooms, 0));
    ingredients.insert(std::make_pair(Steak, 0));
    ingredients.insert(std::make_pair(Eggplant, 0));
    ingredients.insert(std::make_pair(GoatCheese, 0));
    ingredients.insert(std::make_pair(ChiefLove, 0));

    is >> cooksNb;
    for (size_t i = 0; i < cooksNb; i++)
        cookIsCooking.push_back(false);

    for (int i = 0; i < cooksNb; i++) {
        int temp;
        is >> temp;
        if (is.fail())
            break;
        cookIsCooking[i] = temp != 0;
    }
    for (int i = 0; i < 8; i++)
        is >> ingredients[static_cast<PizzaIngredient>(i)];

    status.setCookIsCooking(cookIsCooking);
    status.setIngredients(ingredients);
    return is;
}

void sendStatus(Status &Status, int fd)
{
    std::stringstream str;

    str << 2 << Status;
    write(fd, str.str().c_str(), str.str().size());
}

void sendStatusRequest(int fd)
{
    std::stringstream str;

    str << 2;
    write(fd, str.str().c_str(), str.str().size());
}

Status receiveStatus(int fd, size_t cooksNb)
{
    size_t str_to_read_size = 8 + cooksNb * 2 + 9 * ((8) + 1) + 1;
    // size_t cooks_nb, spaces and bool, spaces and ingredients, terminating null byte

    char buff[str_to_read_size];
    std::stringstream ss;
    Status Status;

    memset(buff, 0, str_to_read_size);
    size_t size = read(fd, buff, str_to_read_size - 1);
    if (size == 0)
        return Status;
    std::string str(buff, size);
    ss << str;
    ss >> Status;
    return Status;
}
