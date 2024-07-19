/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef RECEPTION_DATA_HPP
#define RECEPTION_DATA_HPP

#include "base.hpp"
#include "kitchen.hpp"
#include "process.hpp"
#include "safe_value.hpp"

class ReceptionData {
public:
    ReceptionData(double multiplier, int cooks, int replace_time);
    ~ReceptionData();

    std::list<std::pair<int, Process<int, int, double>>> &getKitchens();
    std::vector<APizza> &getPizzas();
    [[nodiscard]] double getMultiplier() const;
    [[nodiscard]] int getCooksNb() const;
    [[nodiscard]] int getReplaceTime() const;
    [[nodiscard]] bool getEnded() const;
    void setEnded();
    void setStatusToGet(bool);
    bool getStatusToGet() const;
    std::list<size_t> &getKitchenPizzasAmount();
    void addKitchen(int cooks_nb, int replace_time, double multiplier);

private:
    std::list<std::pair<int, Process<int, int, double>>> _kitchens;
    std::list<size_t> _kitchen_pizzas_amount;
    std::vector<APizza> _pizzas;
    double _multiplier;
    int _cooks;
    int _replace_time;
    bool _ended;
    bool _statusToGet;
};

#endif //RECEPTION_DATA_HPP
