/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP

#include "base.hpp"

template<typename T>
class SafeQueue {
public:
    SafeQueue()
        : _queue(),
          _mutex()
    {
    }

    ~SafeQueue()
    {
    };

    void push(T value)
    {
        std::unique_lock lock(_mutex);

        _queue.push_back(value);
    }

    bool isEmpty() {
        std::unique_lock lock(_mutex);

        return _queue.empty();
    }

    size_t getLength() {
        std::unique_lock lock(_mutex);

        return _queue.size();
    }

    size_t tryGetLength() {
        bool x = _mutex.try_lock();

        if (!x)
            return -1;
        size_t size = _queue.size();
        _mutex.unlock();
        return size;
    }

    T tryPop()
    {
        std::unique_lock lock(_mutex);
        T value;

        if (_queue.empty())
            return value;
        value = _queue.front();
        _queue.pop_front();
        return value;
    }

    T &getFirstElemUnsafe()
    {
        return _queue.front();
    }

    T getFirstElemCopy()
    {
        std::unique_lock lock(_mutex);

        return _queue.front();
    }

private:
    std::list<T> _queue;
    std::mutex _mutex;
};

#endif //SAFE_QUEUE_HPP
