/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef SAFE_VALUE_HPP
    #define SAFE_VALUE_HPP

    #include "base.hpp"

template<typename T>
class SafeValue {
public:
    SafeValue()
        : _value(),
          _mutex()
    {
    }
    SafeValue(T value)
        : _value(value),
          _mutex()
    {
    }

    ~SafeValue()
    {
    };

    void setValue(T value)
    {
        std::unique_lock lock(_mutex);

        _value = value;
    }

    T &getValue()
    {
        std::unique_lock lock(_mutex);

        return _value;
    }

    void setValueUnsafe(T value)
    {
        _value = value;
    }

    T &getValueUnsafe()
    {
        return _value;
    }

    void lock()
    {
        _mutex.lock();
    }

    void unlock()
    {
        _mutex.unlock();
    }

    std::mutex &getMutex()
    {
        return _mutex;
    }

private:
    T _value;
    std::mutex _mutex;
};

#endif //SAFE_VALUE_HPP
