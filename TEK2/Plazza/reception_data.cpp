/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/reception_data.hpp"

ReceptionData::ReceptionData(double multiplier, int cooks, int replace_time)
    : _kitchens(std::list<std::pair<int, Process<int, int, double>>>()),
      _kitchen_pizzas_amount(std::list<size_t>()),
      _pizzas(std::vector<APizza>()),
      _multiplier(multiplier),
      _cooks(cooks),
      _replace_time(replace_time),
      _ended(false),
      _statusToGet(false)
{
}

ReceptionData::~ReceptionData()
{
}

std::list<std::pair<int, Process<int, int, double>>> &ReceptionData::getKitchens()
{
    return _kitchens;
}

std::vector<APizza> &ReceptionData::getPizzas()
{
    return _pizzas;
}

double ReceptionData::getMultiplier() const
{
    return _multiplier;
}

int ReceptionData::getCooksNb() const
{
    return _cooks;
}

int ReceptionData::getReplaceTime() const
{
    return _replace_time;
}

std::list<size_t> &ReceptionData::getKitchenPizzasAmount()
{
    return _kitchen_pizzas_amount;
}

bool ReceptionData::getEnded() const
{
    return _ended;
}

void ReceptionData::setEnded()
{
    _ended = true;
}

void ReceptionData::setStatusToGet(bool a)
{
    _statusToGet = a;
}

bool ReceptionData::getStatusToGet() const
{
    return _statusToGet;
}

void ReceptionData::addKitchen(int cooks_nb, int replace_time, double multiplier)
{
    _kitchens.emplace_back(std::piecewise_construct,
        std::forward_as_tuple(0),
        std::forward_as_tuple(processNewKitchen, cooks_nb, replace_time, multiplier));

    _kitchens.back().first = _kitchens.back().second.getPid();
}
