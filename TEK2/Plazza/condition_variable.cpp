/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/condition_variable.hpp"

ConditionVariable::ConditionVariable()
{
}

ConditionVariable::~ConditionVariable()
{
}

void ConditionVariable::waitUntil(size_t milliseconds)
{
    std::unique_lock<std::mutex> lck(_mutex);
    _cv.wait_until(lck, std::chrono::system_clock::now() + std::chrono::milliseconds(milliseconds));
}

void ConditionVariable::notifyAll()
{
    _cv.notify_all();
}

void ConditionVariable::waitNotification()
{
    std::unique_lock<std::mutex> lck(_mutex);
    _cv.wait(lck);
}
