/*
** EPITECH PROJECT, 2022
** init_stat_chara3.c
** File description:
** Init stat character.
*/

#include "my.h"

stat_cara_t stat_cara_four(void)
{
    stat_cara_t stat;
    sfTexture *text = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    stat.sprite = set_sprite(text, set_pos(900, 500), set_pos(3, 3));
    stat.area = 35;
    stat.life = 70;
    stat.speed = 5;
    stat.magnet = 40;
    stat.max_life = 70;
    stat.rect = 0;
    stat.ms = 12;
    stat.dir = 0;
    stat_cara_four2(&stat);
    return stat;
}

void stat_cara_five2(stat_cara_t *stat)
{
    stat->armor = 5;
    stat->cooldown = 10;
    stat->pene = 2;
    stat->recov = 1;
    stat->growth = 0;
    stat->duration = 10;
    stat->rect = malloc(sizeof(sfIntRect) * 4);
    stat->rect[0] = pos_rect(236, 0, 27, 35);
    stat->rect[1] = pos_rect(238, 56, 27, 32);
    stat->rect[2] = pos_rect(375, 34, 27, 32);
    stat->rect[3] = pos_rect(445, 35, 28, 32);
}

stat_cara_t stat_cara_five(void)
{
    stat_cara_t stat;
    sfTexture *text = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    stat.sprite = set_sprite(text, set_pos(900, 500), set_pos(3, 3));
    stat.area = 20;
    stat.life = 100;
    stat.speed = 7;
    stat.magnet = 30;
    stat.max_life = 100;
    stat.rect = 0;
    stat.ms = 12;
    stat.dir = 0;
    stat_cara_five2(&stat);
    return stat;
}

void stat_cara_six2(stat_cara_t *stat)
{
    stat->armor = 5;
    stat->cooldown = 35;
    stat->pene = 3;
    stat->recov = 1;
    stat->growth = 0;
    stat->duration = 10;
    stat->rect = malloc(sizeof(sfIntRect) * 4);
    stat->rect[0] = pos_rect(203, 29, 24, 33);
    stat->rect[1] = pos_rect(102, 84, 24, 32);
    stat->rect[2] = pos_rect(204, 56, 24, 32);
    stat->rect[3] = pos_rect(272, 91, 25, 32);
}

stat_cara_t stat_cara_six(void)
{
    stat_cara_t stat;
    sfTexture *text = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    stat.sprite = set_sprite(text, set_pos(900, 500), set_pos(3, 3));
    stat.area = 20;
    stat.life = 120;
    stat.speed = 11;
    stat.magnet = 30;
    stat.max_life = 120;
    stat.rect = 0;
    stat.ms = 8;
    stat.dir = 0;
    stat_cara_six2(&stat);
    return stat;
}
