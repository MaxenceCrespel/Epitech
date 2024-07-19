/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    char stock;

    while (a < b) {
        stock = str[a];
        str[a] = str[b];
        str[b] = stock;
        a++;
        b--;
    }
    return (str);
}
