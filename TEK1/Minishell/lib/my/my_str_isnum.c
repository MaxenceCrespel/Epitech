/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_str_isnum
*/

int my_str_isnum(char *str)
{
    int a = 0;

    if (str[0] == '-')
        a = 1;
    for (; str[a] != '\0'; a++) {
        if (str[a] < '0' || str[a] > '9')
            return 0;
    }
    return 1;
}
