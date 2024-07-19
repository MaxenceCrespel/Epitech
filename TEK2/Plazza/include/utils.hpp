/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef UTILS_HPP
    #define UTILS_HPP

    #include "base.hpp"
    #include <cctype>

class UtilsException : public std::exception {
public:
    explicit UtilsException(std::string msg)
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


std::string toLowerCase(const std::string& str);
std::string strip(const std::string& str);

template<typename T>
void eraseFromList(std::list<T> &list, size_t index)
{
    auto it = list.begin();

    for (size_t i = 0; i < index; i++)
        it++;
    list.erase(it);
}

bool checkIfCanRead(int fd);

#endif //UTILS_HPP
