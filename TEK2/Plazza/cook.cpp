/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include <utility>

#include "include/cook.hpp"

Cook::Cook(
    const std::shared_ptr<SafeQueue<APizza>> &queue, const std::shared_ptr<std::mutex> &mutex,
    std::shared_ptr<SafeValue<bool>> &end_thread,
    std::shared_ptr<SafeValue<std::map<PizzaIngredient, size_t>>> &ingredients,
    std::shared_ptr<ConditionVariable> &cond_var,
    std::pair<int, int> fds
)
    : _queue(queue),
      _mutex(mutex),
      _end_thread(end_thread),
      _ingredients(ingredients),
      _cond_var(cond_var),
      _fds(std::move(fds))
{
}

Cook::~Cook()
{
}

void Cook::processCook()
{
    while (42) {
        if (_end_thread->getValue())
            break;
        if (!_queue->isEmpty()) {
            auto pizza = _queue->getFirstElemCopy();

            if (!checkIfCanCook(pizza)) {
                _cond_var->waitNotification();
                continue;
            }
            int cookingTime = static_cast<int>(static_cast<double>(pizza.getCookingTime() * 1000));

            std::this_thread::sleep_for(std::chrono::milliseconds(cookingTime));
            _mutex->lock();
            sendPizza(pizza, _fds.second);
            _mutex->unlock();
            _queue->tryPop();
        } else
            std::this_thread::sleep_for(std::chrono::microseconds(500));
    }
}

bool Cook::checkIfCanCook(APizza &pizza)
{
    auto ingredients = APizza::getIngredientsFromPizzaType(pizza.getType());
    _ingredients->lock();

    for (auto &ingredient : ingredients) {
        if (_ingredients->getValueUnsafe()[ingredient] == 0) {
            _ingredients->unlock();
            return false;
        }
    }
    for (auto &ingredient : ingredients)
        _ingredients->getValueUnsafe()[ingredient] -= 1;
    _ingredients->unlock();
    return true;
}

void processNewCook(
    const std::shared_ptr<SafeQueue<APizza>> queue, const std::shared_ptr<std::mutex> mutex,
    std::shared_ptr<SafeValue<bool>> end_thread,
    std::shared_ptr<SafeValue<std::map<PizzaIngredient, size_t>>> ingredients,
    std::shared_ptr<ConditionVariable> cond_var,
    std::pair<int, int> fds
)
{
    Cook cook(queue, mutex, end_thread, ingredients, cond_var, fds);

    cook.processCook();
}
