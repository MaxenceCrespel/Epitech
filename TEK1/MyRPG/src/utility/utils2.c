/*
** EPITECH PROJECT, 2022
** utils
** File description:
** defender
*/

#include "my.h"

sfText *put_text(sfVector2f pos, int size, char *msg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("asset/font.ttf");
    sfText_setString(text, msg);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    return text;
}

sfColor ini_color(int r, int g, int b, int a)
{
    sfColor color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return (color);
}

int *my_intdup(int *cp, int len)
{
    int *result = malloc(len *sizeof(int));
    for (int i = 0; i < len; i++)
        result[i] = cp[i];
    return result;
}

sfVector2f set_pos(float x, float y)
{
    sfVector2f pos;
    pos.x = x;
    pos.y = y;
    return pos;
}

sfIntRect pos_rect(int top, int left, int width, int height)
{
    sfIntRect pos;
    pos.height = height;
    pos.left = left;
    pos.top = top;
    pos.width = width;
    return pos;
}
