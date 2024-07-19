/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strlowcase
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int a = 0;

    while (a < my_strlen(str)) {
        if (str[a] > 64 && str[a] < 91)
            str[a] = str[a] + 32;
        a++;
    }
    return str;
}
