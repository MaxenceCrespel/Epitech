/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef CONDITION_VARIABLE_HPP
    #define CONDITION_VARIABLE_HPP

    #include "base.hpp"

class ConditionVariableException : public std::exception {
public:
    explicit ConditionVariableException(std::string msg)
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

class ConditionVariable {
public:
    ConditionVariable();
    ~ConditionVariable();
    void waitUntil(size_t milliseconds);
    void notifyAll();
    void waitNotification();
private:
    std::condition_variable _cv;
    std::mutex _mutex;
};

#endif //CONDITION_VARIABLE_HPP
