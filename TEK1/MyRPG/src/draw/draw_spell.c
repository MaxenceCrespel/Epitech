/*
** EPITECH PROJECT, 2022
** draw_spell.c
** File description:
** Draw spell.
*/

#include "my.h"

void display_img_attack(game_t *g)
{
    sfSprite *copy_img;
    for (int i = 0; i < 6; i++) {
        if (g->start.attack[i].att.img.sprite == NULL)
            continue;
        if (g->start.attack[i].have == 1 || (g->start.attack[i].status == 3
        && g->start.lorel >= 1))
            sfRenderWindow_drawSprite(g->window,
            g->start.attack[i].att.img.sprite, NULL);
        else {
            copy_img = sfSprite_copy(g->start.attack[i].att.img.sprite);
            sfSprite_setColor(copy_img,
            sfColor_fromRGBA(255, 255, 255, 115));
            sfRenderWindow_drawSprite(g->window, copy_img, NULL);
            sfSprite_destroy(copy_img);
        }
    }
}

void display_bar_life(game_t *g, bar_health bar)
{
    sfRenderWindow_drawSprite(g->window, bar.bg, NULL);
    sfRenderWindow_drawRectangleShape(g->window, bar.bar, NULL);
    sfRenderWindow_drawSprite(g->window, bar.front, NULL);
}

void display_lorel(game_t *g, sfSprite *lorel, int nb)
{
    sfSprite *cpy = sfSprite_copy(lorel);
    if (nb == 2)
        sfSprite_setColor(cpy, sfColor_fromRGB( 142, 68, 173 ));
    if (nb == 3)
        sfSprite_setColor(cpy, sfGreen);
    if (nb == 4)
        sfSprite_setColor(cpy, sfMagenta);
    if (nb == 5)
        sfSprite_setColor(cpy, sfCyan);
    if (nb == 6)
        sfSprite_setColor(cpy, sfColor_fromRGB( 33, 97, 140));
    sfRenderWindow_drawSprite(g->window, cpy, NULL);
}

void draw_cryst(game_t *g)
{
    add_crist_t *tmp = g->start.d_crys;

    while (tmp) {
        sfRenderWindow_drawSprite(g->window, tmp->cryst.sprite, NULL);
        tmp = tmp->next;
    }
}

void display_game_two(game_t *g)
{
    if (g->option.img[3].status == 0 && g->start.nb_text > 0)
        display_text(g);
    if (g->start.nb_attack > 0)
        draw_attack(g);
    if (g->start.nb_monster > 0)
        draw_monster(g);
    if (g->start.nb_cryst > 0)
        draw_cryst(g);
    if (g->scene == 1)
        display_img_attack(g);
    if (g->scene == 3) {
        sfRenderWindow_drawSprite(g->window, g->start.inv.bg.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->start.inv.empty_s.sprite,
        NULL);
        draw_slot_attack_def(g);
        draw_stat_in(g);
        draw_item(g);
    }
}
