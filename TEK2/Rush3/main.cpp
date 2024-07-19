/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main
*/

#include "GraphicalMode.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "TextMode.hpp"

int helper()
{
    std::cout << "MyGKrellm usage: \n\nParameter:\n\nbinary -g          Display graphical application.\nbinary -t          Display text mode.\nbinary -h --help   Display helper." << std::endl;
    return (0);
}

int graphicalMode()
{
    GraphicalMode graphicalMode;

    graphicalMode.displayerGraphicalMode();
    return (0);
}

int main(int args, char **argv)
{
    if (args == 1)
        return (helper());
    if (strcmp(argv[1], "-g") == 0)
        return (graphicalMode());
    if (strcmp(argv[1], "-t") == 0)
        return (displayTextMode());
    if (strcmp(argv[1], "-h") == 0|| strcmp(argv[1], "--help") == 0)
        helper();
    return (0);
}