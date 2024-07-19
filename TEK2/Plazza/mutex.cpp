/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/mutex.hpp"

Mutex::Mutex()
    : _mutex()
{
}

void Mutex::lock()
{
    try {
        _mutex.lock();
    } catch (std::exception &e) {
        throw MutexException("Mutex lock failed");
    }
}

void Mutex::trylock()
{
    _mutex.try_lock();
}

void Mutex::unlock()
{
    try {
        _mutex.unlock();
    } catch (std::exception &e) {
        throw MutexException("Mutex unlock failed");
    }
}
