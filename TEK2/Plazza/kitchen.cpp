/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include <utility>

#include "include/kitchen.hpp"

Kitchen::Kitchen(std::pair<int, int> fds, int cooks_nb, int replace_time, double multiplier)
    : _cooks_nb(cooks_nb),
      _replace_time(replace_time),
      _multiplier(multiplier),
      _threads(),
      _pizzas_queue(),
      _cooks_queues({}),
      _mutex(std::make_shared<std::mutex>()),
      _cookIsCooking({}),
      _end_thread(std::make_shared<SafeValue<bool>>(false)),
      _ingredients(std::make_shared<SafeValue<std::map<PizzaIngredient, size_t>>>()),
      _cond_var(std::make_shared<ConditionVariable>()),
      _fds(std::move(fds))
{
    _cooks_queues.reserve(_cooks_nb);
    _cookIsCooking.reserve(_cooks_nb);

    for (int i = 0; i < _cooks_nb; i++)
        _cookIsCooking.push_back(false);

    std::map<PizzaIngredient, size_t> ingredients;

    ingredients.insert(std::make_pair(Dough, 5));
    ingredients.insert(std::make_pair(Tomato, 5));
    ingredients.insert(std::make_pair(Gruyere, 5));
    ingredients.insert(std::make_pair(Ham, 5));
    ingredients.insert(std::make_pair(Mushrooms, 5));
    ingredients.insert(std::make_pair(Steak, 5));
    ingredients.insert(std::make_pair(Eggplant, 5));
    ingredients.insert(std::make_pair(GoatCheese, 5));
    ingredients.insert(std::make_pair(ChiefLove, 5));

    _ingredients->setValue(ingredients);
}

Kitchen::~Kitchen() = default;

void Kitchen::processKitchen()
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point start_ingredients = std::chrono::steady_clock::now();
    bool stuff_happened = false;

    for (int i = 0; i < _cooks_nb; i++) {
        _cooks_queues.push_back(std::make_shared<SafeQueue<APizza>>());
        _threads.emplace_back(processNewCook, _cooks_queues[i], _mutex, _end_thread, _ingredients, _cond_var, _fds);
    }

    while (42) {
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsed = now - start;
        std::chrono::duration<float> elapsed_ingredients = now - start_ingredients;

        if (elapsed_ingredients.count() * 1000 >= static_cast<double> (_replace_time)) {
            _ingredients->lock();
            for (auto &ingredient: _ingredients->getValueUnsafe())
                ingredient.second += 1;
            _ingredients->unlock();
            start_ingredients = std::chrono::steady_clock::now();
            _cond_var->notifyAll();
        }
        if (elapsed.count() >= 5 && !stuff_happened && !atLeastOneCookCooking())
            break;
        if (stuff_happened) {
            start = std::chrono::steady_clock::now();
            stuff_happened = false;
        }

        while (tryGetDataFromFd(stuff_happened));
        while (sendPizzaToCooks(stuff_happened));
        trySeeIfNotCooking(stuff_happened);

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    _end_thread->setValue(true);
    for (int i = 0; i < _cooks_nb; i++) {
        _threads[i].join();
    }
}

bool Kitchen::atLeastOneCookCooking()
{
    for (int i = 0; i < _cooks_nb; i++) {
        if (_cookIsCooking[i])
            return true;
    }
    return false;
}

void Kitchen::trySeeIfNotCooking(bool &stuff_happened)
{
    for (int i = 0; i < _cooks_nb; i++) {
        if (_cooks_queues[i]->isEmpty() && _cookIsCooking[i]) {
            stuff_happened = true;
            _cookIsCooking[i] = false;
        }
    }
}

bool Kitchen::sendPizzaToCooks(bool &stuff_happened)
{
    std::unique_lock<std::mutex> lock(_pizzas_queue.getMutex());

    if (_pizzas_queue.getValueUnsafe().empty())
        return false;

    bool has_one_empty = false;
    for (int i = 0; i < _cooks_nb; i++) {
        if (_cooks_queues[i]->isEmpty()) {
            has_one_empty = true;
            break;
        }
    }
    if (!has_one_empty)
        return false;

    APizza pizza = _pizzas_queue.getValueUnsafe().front();
    _pizzas_queue.getValueUnsafe().pop_front();

    for (int i = 0; i < _cooks_nb; i++) {
        if (_cooks_queues[i]->getLength() == 0) {
            _cooks_queues[i]->push(pizza);
            stuff_happened = true;
            _cookIsCooking[i] = true;
            return true;
        }
    }
    return true;
}

bool Kitchen::tryGetDataFromFd(bool &stuff_happened)
{
    std::string buffer;

    try {
        buffer = tryRead(1);
    } catch (const KitchenException &e) {
        return false;
    }

    if (buffer.length() == 0 || (buffer[0] != '1' && buffer[0] != '2'))
        return false;

    if (buffer[0] == '1') {
        if (!checkIfCanRead(_fds.first))
            return false;
        APizza pizza = receivePizza(_fds.first);
        pizza.setCookingTime(APizza::getCookingTimeFromPizzaType(pizza.getType()), _multiplier);
        _pizzas_queue.lock();
        _pizzas_queue.getValueUnsafe().push_back(pizza);
        _pizzas_queue.unlock();
        stuff_happened = true;
        return true;
    }
    if (buffer[0] == '2') {
        _ingredients->lock();
        Status status(_cookIsCooking, _ingredients->getValueUnsafe());
        _ingredients->unlock();

        _mutex->lock();
        sendStatus(status, _fds.second);
        _mutex->unlock();
    }
    return true;
}

std::string Kitchen::tryRead(size_t strSize)
{
    if (!checkIfCanRead(_fds.first))
        return "";

    char buffer[4096];
    size_t size;

    if ((size = read(_fds.first, buffer, strSize)) == -1)
        throw KitchenException("Read failed");
    if (size < strSize)
        strSize = size;
    buffer[strSize] = '\0';
    return {buffer};
}

void processNewKitchen(std::pair<int, int> fds, int cooks_nb, int _replace_time, double multiplier)
{
    Kitchen kitchen(fds, cooks_nb, _replace_time, multiplier);

    kitchen.processKitchen();

    std::string end("9"); // meaning end
    write(fds.second, end.c_str(), end.length());
}
