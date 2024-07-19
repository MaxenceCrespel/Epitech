/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef MUTEX_HPP
    #define MUTEX_HPP

    #include "base.hpp"

class MutexException : public std::exception {
public:
    explicit MutexException(std::string msg)
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

class Mutex {
public:
    Mutex();
    ~Mutex() = default;
    void lock();
    void unlock();
    void trylock();

private:
    std::mutex _mutex;
};

#endif //MUTEX_HPP
