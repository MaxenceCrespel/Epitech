/*
** EPITECH PROJECT, 2022
** init_monster2.c
** File description:
** Init monster.
*/

#include "my.h"

monster_t create_monster_two(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(3, 3));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(15, 0));
    list.life = 70;
    list.speed = 1.7;
    list.damage = 10;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(1004, 1362, 29, 31);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(792, 1435, 30, 31);
    list.rect[2] = pos_rect(1004, 1362, 29, 31);
    list.rect[3] = pos_rect(792, 1435, 30, 31);
    return list;
}

monster_t create_monster_tree(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(3, 3));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(12, 0));
    list.life = 75;
    list.speed = 2.3;
    list.damage = 13;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(1041, 1390, 28, 28);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(921, 1722, 25, 33);
    list.rect[2] = pos_rect(1041, 1390, 28, 28);
    list.rect[3] = pos_rect(921, 1722, 25, 33);
    return list;
}

monster_t create_monster_four(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(3, 3));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(23, 0));
    list.life = 75;
    list.speed = 2.4;
    list.damage = 17;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(268, 388, 55, 45);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(358, 1766, 49, 45);
    list.rect[2] = pos_rect(491, 1276, 46, 45);
    list.rect[3] = pos_rect(358, 1766, 49, 45);
    return list;
}

monster_t create_monster_five(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(3, 3));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(21, 0));
    list.life = 235;
    list.speed = 2.7;
    list.damage = 30;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(306, 1904, 44, 48);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(509, 1746, 43, 50);
    list.rect[2] = pos_rect(597, 1277, 44, 52);
    list.rect[3] = pos_rect(562, 1746, 44, 50);
    return list;
}

monster_t create_monster_six(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(3, 3));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(23, 0));
    list.life = 220;
    list.speed = 2.7;
    list.damage = 30;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(607, 1471, 45, 47);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(673, 1841, 43, 46);
    list.rect[2] = pos_rect(557, 1057, 46, 47);
    list.rect[3] = pos_rect(673, 1841, 43, 46);
    return list;
}
