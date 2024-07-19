/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/reception.hpp"

int error_handling(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: ./plazza [multiplier] [nb_cooks] [replace_time]" << std::endl;
        return (84);
    }
    try {
        if (std::stof(argv[1]) < 0 || std::stoi(argv[2]) <= 0 || std::stoi(argv[3]) <= 0) {
            std::cerr << "Error: every arg must be greater than 0, or equal for multiplicative" << std::endl;
            return (84);
        }
    } catch (std::exception &e) {
        std::cerr << "Error: every arg must be a number in the size of int" << std::endl;
        return (84);
    }
    //check if log.txt can be accessed and modified, aswell as clearing it:
    std::ofstream file("log.txt");
    if (!file.is_open()) {
        std::cerr << "Error: log.txt cannot be accessed" << std::endl;
        return (84);
    }
    file << "";
    file.close();
    return (0);
}

int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == 84)
        return (84);
    Reception reception(argv);
    reception.runShell();
    return (0);
}