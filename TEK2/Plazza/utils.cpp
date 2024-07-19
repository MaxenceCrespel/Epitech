/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/utils.hpp"

std::string toLowerCase(const std::string& str)
{
    std::string result;

    for (char c : str)
        result += std::tolower(c);
    return result;
}

std::string strip(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

bool checkIfCanRead(int fd)
{
    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(fd, &readSet);

    struct timeval timeout{0, 0};

    int ready = select(fd + 1, &readSet, nullptr, nullptr, &timeout);
    if (ready == -1) {
        throw UtilsException("Select failed");
    } else if (ready == 0) {
        return false;
    } else {
        if (FD_ISSET(fd, &readSet))
            return true;
        else
            return false;
    }
}
