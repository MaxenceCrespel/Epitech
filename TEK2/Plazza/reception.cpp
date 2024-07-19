/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/reception.hpp"

Reception::Reception(char **av)
    : _reception_data(std::make_shared<SafeValue<std::shared_ptr<ReceptionData>>>(
    std::make_shared<ReceptionData>(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]))))
{
    std::cout << "Welcome to the reception !" << std::endl;
    appendToLogFile("Starting reception\n");
}

Reception::~Reception()
{
}

void Reception::runShell()
{
    std::string buffer;
    Thread backProcess(process_reception_backprocess, _reception_data);

    while (std::getline(std::cin, buffer)) {
        if (buffer.empty())
            continue;
        if (buffer == "status") {
            _reception_data->lock();
            _reception_data->getValueUnsafe()->setStatusToGet(true);
            _reception_data->unlock();
            continue;
        }
        if (!parsePizzaString(buffer))
            std::cerr << "Error: invalid command" << std::endl;
        else
            appendToLogFile("> " + buffer + "\n");
    }
    _reception_data->getValueUnsafe()->setEnded();
    backProcess.join();
}

bool Reception::parsePizzaString(std::string str)
{
    const std::regex pizzaPattern(R"((?=[^\s])([a-zA-Z]+)\s(S|M|L|XL|XXL)\sx([1-9][0-9]*)(;\s|$))");
    const std::vector<std::string> validPizzas = {"regina", "margarita", "americana", "fantasia"};

    std::smatch match;
    std::list<std::pair<PizzaType, PizzaSize>> pizzas;

    if(str.back() == ';')
        return false;

    while (std::regex_search(str, match, pizzaPattern)) {
        std::string prefix = match.prefix().str();
        if (prefix.length() != 0)
            return false;

        std::string type = match[1].str();
        std::transform(type.begin(), type.end(), type.begin(),
            [](unsigned char c) {return std::tolower(c);});

        std::string size = match[2].str();
        std::string number = match[3].str();

        bool isValidPizza = std::find(validPizzas.begin(), validPizzas.end(), type) != validPizzas.end();

        if (!isValidPizza)
            return false;

        try {
            std::stoi(number);
        } catch (std::exception &e) {
            std::cout << "Error: invalid number of pizzas, number must be of int size" << std::endl;
            return false;
        }

        for (int i = 0; i < std::stoi(number); i++)
            pizzas.emplace_back(MapPizzaType[type], MapPizzaSize[size]);

        str = match.suffix();
    }

    if (str.length() != 0)
        return false;

    for (auto &pizza: pizzas)
        addPizzaToSpare(pizza.first, pizza.second);
    return true;
}

void Reception::addPizzaToSpare(PizzaType type, PizzaSize size)
{
    std::unique_lock<std::mutex> lock(_reception_data->getMutex());
    std::vector<APizza> &pizza_list = _reception_data->getValueUnsafe()->getPizzas();
    double multiplier = _reception_data->getValueUnsafe()->getMultiplier();

    switch (type) {
    case Margarita:
        pizza_list.emplace_back(PizzaMargarita(size, multiplier));
        break;
    case Regina:
        pizza_list.emplace_back(PizzaRegina(size, multiplier));
        break;
    case Americana:
        pizza_list.emplace_back(PizzaAmericana(size, multiplier));
        break;
    case Fantasia:
        pizza_list.emplace_back(PizzaFantasia(size, multiplier));
        break;
    }
}
