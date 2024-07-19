/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef RECEPTION_HPP
    #define RECEPTION_HPP

    #include "base.hpp"
    #include "pizzas.hpp"
    #include "utils.hpp"
    #include "reception_backprocess.hpp"
    #include "thread.hpp"
    #include "safe_queue.hpp"
    #include "kitchen.hpp"
    #include "reception_data.hpp"
    #include "log_file.hpp"

class ReceptionException : public std::exception {
public:
    explicit ReceptionException(std::string msg)
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

class Reception {
public:
    Reception(char **av);
    ~Reception();

    void runShell();
    void parseCommand(std::string &command);
    bool parseOneCommand(std::string &command);
    bool parsePizzaString(std::string input);
    void addPizzaToSpare(PizzaType, PizzaSize);

private:
    std::shared_ptr<SafeValue<std::shared_ptr<ReceptionData>>> _reception_data;
};

#endif //RECEPTION_HPP
