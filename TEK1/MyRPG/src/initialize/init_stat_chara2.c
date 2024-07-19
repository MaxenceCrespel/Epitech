/*
** EPITECH PROJECT, 2022
** init_stat_chara2.c
** File description:
** Init stat character.
*/

#include "my.h"

void stat_cara_two2(stat_cara_t *stat)
{
    stat->armor = 5;
    stat->cooldown = 15;
    stat->pene = 2;
    stat->recov = 1;
    stat->growth = 0;
    stat->duration = 5;
    stat->rect = malloc(sizeof(sfIntRect) * 4);
    stat->rect[0] = pos_rect(203, 29, 24, 33);
    stat->rect[1] = pos_rect(102, 84, 24, 32);
    stat->rect[2] = pos_rect(204, 56, 24, 32);
    stat->rect[3] = pos_rect(272, 91, 25, 32);
}

stat_cara_t stat_cara_two(void)
{
    stat_cara_t stat;
    sfTexture *text = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    stat.sprite = set_sprite(text, set_pos(900, 500), set_pos(3, 3));
    stat.area = 20;
    stat.life = 120;
    stat.speed = 12;
    stat.magnet = 25;
    stat.max_life = 120;
    stat.rect = 0;
    stat.ms = 7;
    stat.dir = 0;
    stat_cara_two2(&stat);
    return stat;
}

void stat_cara_three2(stat_cara_t *stat)
{
    stat->armor = 5;
    stat->cooldown = 45;
    stat->pene = 8;
    stat->recov = 1;
    stat->growth = 0;
    stat->duration = 20;
    stat->rect = malloc(sizeof(sfIntRect) * 4);
    stat->rect[0] = pos_rect(236, 0, 27, 35);
    stat->rect[1] = pos_rect(238, 56, 27, 32);
    stat->rect[2] = pos_rect(375, 34, 27, 32);
    stat->rect[3] = pos_rect(445, 35, 28, 32);
}

stat_cara_t stat_cara_three(void)
{
    stat_cara_t stat;
    sfTexture *text = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    stat.sprite = set_sprite(text, set_pos(900, 500), set_pos(3, 3));
    stat.area = 20;
    stat.life = 80;
    stat.speed = 10;
    stat.magnet = 10;
    stat.max_life = 80;
    stat.rect = 0;
    stat.ms = 15;
    stat.dir = 0;
    stat_cara_three2(&stat);
    return stat;
}

void stat_cara_four2(stat_cara_t *stat)
{
    stat->armor = 5;
    stat->cooldown = 30;
    stat->pene = 2;
    stat->recov = 3;
    stat->growth = 0;
    stat->duration = 0;
    stat->rect = malloc(sizeof(sfIntRect) * 4);
    stat->rect[0] = pos_rect(553, 30, 30, 35);
    stat->rect[1] = pos_rect(553, 62, 30, 35);
    stat->rect[2] = pos_rect(373, 3, 30, 35);
    stat->rect[3] = pos_rect(444, 3, 30, 34);
}
