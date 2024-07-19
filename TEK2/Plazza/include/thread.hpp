/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef THREAD_HPP
    #define THREAD_HPP

    #include "base.hpp"

class ThreadException : public std::exception {
public:
    explicit ThreadException(std::string msg)
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

typedef enum thread_state {
    started,
    running,
    dead
} thread_state_t;

class Thread {
public:
    template<typename Func, typename... Args>
    explicit Thread(Func&& func, Args&&... args) : _thread(std::forward<Func>(func), std::forward<Args>(args)...)
    {
        _state = started;
    }
    Thread(Thread&& other) noexcept : _thread(std::move(other._thread)), _state(other._state) {}
    Thread &operator=(Thread&& other) noexcept;
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    ~Thread();
    void join();
    void detach();
    bool joinable();
    thread_state_t getState();
private:
    std::thread _thread;
    thread_state_t _state;
};

#endif //THREAD_HPP
