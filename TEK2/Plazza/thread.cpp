/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/thread.hpp"

Thread &Thread::operator=(Thread&& other) noexcept
{
    if (this != &other)
    {
        if (_thread.joinable())
            _thread.join();
        _thread = std::move(other._thread);
        _state = other._state;
    }
    return *this;
}

Thread::~Thread()
{
    if (_state == running) {
        try {
            join();
        } catch (ThreadException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Thread::join()
{
    try {
        _thread.join();
    } catch (std::exception &e) {
        throw ThreadException("Thread join failed");
    }
}

void Thread::detach()
{
    try {
        _thread.detach();
    } catch (std::exception &e) {
        throw ThreadException("Thread detach failed");
    }
}

bool Thread::joinable()
{
    return _thread.joinable();
}

thread_state_t Thread::getState()
{
    return _state;
}
