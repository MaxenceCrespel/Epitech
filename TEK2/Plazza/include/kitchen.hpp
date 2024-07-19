/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef KITCHEN_HPP
    #define KITCHEN_HPP

    #include "base.hpp"
    #include "thread.hpp"
    #include "safe_queue.hpp"
    #include "pizzas.hpp"
    #include "cook.hpp"
    #include "utils.hpp"
    #include "kitchen_status.hpp"
    #include "condition_variable.hpp"

class KitchenException : public std::exception {
public:
    explicit KitchenException(std::string msg)
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

class Kitchen {
public:
    Kitchen(std::pair<int, int> fds, int cooks_nb, int replace_time, double multiplier);
    ~Kitchen();

    void processKitchen();
    bool tryGetDataFromFd(bool &stuff_happened);
    std::string tryRead(size_t size);
    bool sendPizzaToCooks(bool &stuff_happened);
    void trySeeIfNotCooking(bool &stuff_happened);
    bool atLeastOneCookCooking();

private:
    int _cooks_nb;
    int _replace_time;
    double _multiplier;
    std::vector<Thread> _threads;
    SafeValue<std::list<APizza>> _pizzas_queue;
    std::vector<std::shared_ptr<SafeQueue<APizza>>> _cooks_queues;
    std::vector<bool> _cookIsCooking;
    std::shared_ptr<std::mutex> _mutex;
    std::shared_ptr<SafeValue<bool>> _end_thread;
    std::shared_ptr<SafeValue<std::map<PizzaIngredient, size_t>>> _ingredients;
    std::shared_ptr<ConditionVariable> _cond_var;
    std::pair<int, int> _fds;
};

void processNewKitchen(std::pair<int, int> fds, int cooks_nb, int _replace_time, double multiplier);

#endif //KITCHEN_HPP
