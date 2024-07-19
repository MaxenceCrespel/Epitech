/*
** EPITECH PROJECT, 2022
** ft_reaper.c
** File description:
** Function reaper talk.
*/

#include "my.h"

void draw_win(game_t *g, sfEvent event)
{
    sfRenderWindow_drawRectangleShape(g->window, g->reaper.rect1, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->reaper.rect2, NULL);
}

void boucle_talk_reaper(game_t *g, sfEvent event)
{
    while (g->reaper.stop == 0) {
        display_game(g);
        remove_list_item(g);
        if (g->start.end == 4 || g->start.nb_item == 8)
            draw_win(g, event);
        if (g->start.end == 4)
            sfRenderWindow_drawText(g->window,
            g->reaper.speak[10].text, NULL);
        else {
            sfRenderWindow_drawText(g->window,
            g->reaper.speak[3 + g->start.nb_item].text, NULL);
        }
        g->mouse = sfMouse_getPositionRenderWindow(g->window);
        sfRenderWindow_display(g->window);
        sfRenderWindow_clear(g->window, sfBlack);
        sfRenderWindow_setMouseCursorVisible(g->window, sfTrue);
        while (sfRenderWindow_pollEvent(g->window, &event))
            event_intro(g, event);
    }
}

void talk_reaper(game_t *g, sfEvent event)
{
    sfFloatRect img = sfSprite_getGlobalBounds(g->start.perso.sprite.sprite);
    sfFloatRect reap = sfSprite_getGlobalBounds(g->reaper.reaper.sprite);
    if (sfFloatRect_intersects(&img, &reap, NULL)
    && event.key.code == sfKeyE) {
        if (g->start.nb_item + 3 == 9 && g->start.end == 0) {
            sfMusic_stop(g->music.music[1]);
            destroy_list(&g->start.d_monster);
            g->start.nb_monster = 0;
            g->start.end = 1;
            g->start.d_monster = add_monster(g, 6, g->start.d_monster);
            g->start.d_monster = add_monster(g, 7, g->start.d_monster);
        }
        if (g->start.end == 3) {
            g->start.or_win += 500;
            sfText_setString(g->start.t_or.text, my_itoa(g->start.or_win));
            g->start.end++;
        }
        boucle_talk_reaper(g, event);
    }
    g->reaper.stop = 0;
}

int sound_attack(game_t *g, int attack)
{
    if (attack == 0) {
        sfSound_play(g->sound.sound[12]);
    }
    if (attack == 1) {
        sfSound_play(g->sound.sound[15]);
    }
    if (attack == 2) {
        sfSound_play(g->sound.sound[2]);
    }
    return (0);
}

void event_game(game_t *g, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace)
            attack_zero(g);
        if (event.key.code == sfKeyNum1)
            attack_un(g);
        if (event.key.code == sfKeyNum2)
            attack_deux(g);
    }
    talk_reaper(g, event);
}
