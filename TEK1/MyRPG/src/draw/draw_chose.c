/*
** EPITECH PROJECT, 2022
** draw_chose.c
** File description:
** Draw chose.
*/

#include "my.h"

void draw_slot_attack_def(game_t *g)
{
    for (int i = 0; i < 6; i++)
        if (g->start.attack[i].att.img.sprite)
            sfRenderWindow_drawSprite(g->window,
            g->start.attack[i].att.img.sprite, NULL);
}

void draw_chose(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->level_up.chose1.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->level_up.chose1.img, NULL);
    sfRenderWindow_drawText(g->window, g->level_up.chose1.name.text, NULL);
    if (g->level_up.chose1.have == 0) {
        sfRenderWindow_drawText(g->window, g->level_up.chose1.new.text, NULL);
        sfRenderWindow_drawText(g->window,
        g->level_up.chose1.descri_new.text, NULL);
    } else
        sfRenderWindow_drawText(g->window,
        g->level_up.chose1.descri.text, NULL);
    sfRenderWindow_drawSprite(g->window, g->level_up.chose2.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->level_up.chose2.img, NULL);
    sfRenderWindow_drawText(g->window, g->level_up.chose2.name.text, NULL);
    if (g->level_up.chose2.have == 0) {
        sfRenderWindow_drawText(g->window, g->level_up.chose2.new.text, NULL);
        sfRenderWindow_drawText(g->window,
        g->level_up.chose2.descri_new.text, NULL);
    } else
        sfRenderWindow_drawText(g->window,
        g->level_up.chose2.descri.text, NULL);
}

void draw_attack(game_t *g)
{
    add_attack_t *tmp = g->start.d_attack;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(g->window, tmp->sprite.sprite, NULL);
        tmp = tmp->next;
    }
}

void display_text(game_t *g)
{
    add_text_t *tmp = g->start.d_text;

    while (tmp != NULL) {
        sfRenderWindow_drawText(g->window, tmp->damage.text, NULL);
        tmp = tmp->next;
    }
}

void draw_monster(game_t *g)
{
    add_monster_t *tmp = g->start.d_monster;

    while (tmp) {
        sfRenderWindow_drawSprite(g->window, tmp->sprite.sprite, NULL);
        tmp = tmp->next;
    }
}
