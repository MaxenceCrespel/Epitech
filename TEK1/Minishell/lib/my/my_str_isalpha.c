/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        if (str[a] < 65 || (str[a] > 90 && str[a] < 97) || str[a] > 122)
            return 0;
        a++;
    }
    return 1;
}
