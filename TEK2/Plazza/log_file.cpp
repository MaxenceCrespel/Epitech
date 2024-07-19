/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/log_file.hpp"

void appendToLogFile(const std::string &str)
{
    std::ofstream file("log.txt", std::ios_base::app);
    file << str << std::endl;
    file.close();
}
