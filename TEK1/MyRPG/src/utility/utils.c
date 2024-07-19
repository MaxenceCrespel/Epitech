/*
** EPITECH PROJECT, 2022
** utils
** File description:
** defender
*/

#include "my.h"

my_sprite_t set_sprite(sfTexture *texture, sfVector2f pos, sfVector2f scale)
{
    my_sprite_t my_sprite;

    my_sprite.sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite.sprite, texture, sfTrue);
    sfSprite_setScale(my_sprite.sprite, set_pos(scale.x, scale.y));
    sfSprite_setPosition(my_sprite.sprite, pos);
    return (my_sprite);
}

my_sprite_t set_sprite_rect(sfTexture *texture, sfVector2f pos,
sfVector2f scale, sfIntRect rect)
{
    my_sprite_t my_sprite;

    my_sprite.sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite.sprite, texture, sfTrue);
    sfSprite_setScale(my_sprite.sprite, set_pos(scale.x, scale.y));
    sfSprite_setPosition(my_sprite.sprite, pos);
    sfSprite_setTextureRect(my_sprite.sprite, rect);
    return (my_sprite);
}

sfRectangleShape *create_button(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *button = sfRectangleShape_create();
    sfRectangleShape_setPosition(button, pos);
    sfRectangleShape_setSize(button, size);
    sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0, 0, 0, 128));
    return button;
}

text_t init_text(char *path, int nb, sfVector2f pos, char *str)
{
    text_t text;

    text.font = sfFont_createFromFile(path);
    text.text = sfText_create();
    sfText_setString(text.text, str);
    sfText_setFont(text.text, text.font);
    sfText_setColor(text.text, sfWhite);
    sfText_setCharacterSize(text.text, nb);
    sfText_setPosition(text.text, pos);
    return (text);
}

int verrif_button_rect(game_t *g, sfRectangleShape *spr)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(spr);
    if (sfFloatRect_contains(&rect, g->mouse.x, g->mouse.y)) {
        return (1);
    }
    return 0;
}
