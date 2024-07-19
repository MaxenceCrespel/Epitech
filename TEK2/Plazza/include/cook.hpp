/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef COOK_HPP
#define COOK_HPP

#include "base.hpp"
#include "pizzas.hpp"
#include "safe_queue.hpp"
#include "safe_value.hpp"
#include "condition_variable.hpp"

class CookException : public std::exception {
public:
    explicit CookException(std::string msg)
        : _msg(std::move(msg))
    {
    }

    [[nodiscard]] const char *what() const noexcept override
    {
        return _msg.c_str();
    }

private:
    std::string _msg;
};

class Cook {
public:
    explicit Cook(
        const std::shared_ptr<SafeQueue<APizza>> &queue, const std::shared_ptr<std::mutex> &mutex,
        std::shared_ptr<SafeValue<bool>> &end_thread,
        std::shared_ptr<SafeValue<std::map<PizzaIngredient, size_t>>> &ingredients,
        std::shared_ptr<ConditionVariable> &cond_var,
        std::pair<int, int> fds
    );
    ~Cook();
    void processCook();
    bool checkIfCanCook(APizza &pizza);

private:
    std::shared_ptr<SafeQueue<APizza>> _queue;
    std::shared_ptr<std::mutex> _mutex;
    std::shared_ptr<SafeValue<bool>> &_end_thread;
    std::shared_ptr<SafeValue<std::map<PizzaIngredient, size_t>>> _ingredients;
    std::shared_ptr<ConditionVariable> _cond_var;
    std::pair<int, int> _fds;
};

void processNewCook(
    std::shared_ptr<SafeQueue<APizza>> queue, std::shared_ptr<std::mutex> mutex,
    std::shared_ptr<SafeValue<bool>> end_thread,
    std::shared_ptr<SafeValue<std::map<PizzaIngredient, size_t>>> ingredients,
    std::shared_ptr<ConditionVariable> cond_var,
    std::pair<int, int> fds
);

#endif //COOK_HPP
