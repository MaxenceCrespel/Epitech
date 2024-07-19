/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef STATUS_HPP
#define STATUS_HPP

#include "base.hpp"
#include "pizzas.hpp"
#include "log_file.hpp"

class StatusException : public std::exception {
public:
    explicit StatusException(std::string msg)
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

class Status {
public:
    Status(std::vector<bool> cookIsCooking, std::map<PizzaIngredient, size_t> _ingredients);
    Status();
    ~Status();

    void printStatus();
    [[nodiscard]] std::vector<bool> getCookIsCooking() const;
    void setCookIsCooking(std::vector<bool> cookIsCooking);
    [[nodiscard]] std::map<PizzaIngredient, size_t> getIngredients() const;
    void setIngredients(std::map<PizzaIngredient, size_t> ingredients);

private:
    std::vector<bool> _cookIsCooking;
    std::map<PizzaIngredient, size_t> _ingredients;
};

void sendStatus(Status &status, int fd);
void sendStatusRequest(int fd);
Status receiveStatus(int fd, size_t cooksNb);

std::ostream &operator<<(std::ostream &os, const Status &pizza);
std::istream &operator>>(std::istream &is, Status &pizza);

#endif //STATUS_HPP
