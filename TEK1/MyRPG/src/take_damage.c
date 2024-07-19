/*
** EPITECH PROJECT, 2022
** take_damage.c
** File description:
** Take damage.
*/

#include "my.h"

void change_bar_hp(bar_health bar, int value, int max_value)
{
    float my_value = (float)value / (float)max_value;
    float max_bar = 67;
    sfVector2f size = set_pos(67 * my_value, 6);
    if (size.x < max_bar / 2)
        sfRectangleShape_setFillColor(bar.bar, sfYellow);
    else if (size.x < max_bar / 4)
        sfRectangleShape_setFillColor(bar.bar, sfRed);
    else
        sfRectangleShape_setFillColor(bar.bar, sfGreen);
    sfRectangleShape_setSize(bar.bar, size);
}

void take_damage(game_t *g, int nb)
{
    if (g->start.lorel == 0) {
        g->start.perso.life -= nb;
        sfSound_play(g->sound.sound[LOWHP]);
        change_bar_hp(g->start.bar, g->start.perso.life,
        g->start.perso.max_life);
        return;
    }
    for (int i = 0; i < 6; i++)
        if (g->start.attack[i].status == 3)
            sfClock_restart(g->start.attack[i].clock);
    g->start.lorel--;
}

int sound_pause(game_t *g)
{
    if (g->pause == 0) {
        g->pause = 1;
        sfSound_play(g->sound.sound[PAUSE_IN]);
        return (0);
    }
    if (g->pause == 1) {
        g->pause = 0;
        sfSound_play(g->sound.sound[PAUSE_OUT]);
    }
    return (0);
}

void event_key_two(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeyB && g->scene == 1)
        take_damage(g, 10);
    if (event.key.code == sfKeyG)
        add_gold(g, 1000);
    if (event.key.code == sfKeyEscape && g->scene == 1) {
        g->old_scene = 1;
        g->scene = 5;
        sound_pause(g);
    } else if (event.key.code == sfKeyEscape
    && g->scene == 5 && g->old_scene == 1) {
        g->scene = 1;
        g->old_scene = 5;
        sound_pause(g);
    }
    event_key_three(g, event);
}

void event_key(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeyTab && g->scene == 1)
        g->scene = 3;
    else if (event.key.code == sfKeyTab && g->scene == 3)
        g->scene = 1;
    if ((event.key.code == sfKeyEscape && g->scene == 0))
        sfRenderWindow_close(g->window);
    if ((event.key.code == sfKeyEscape && g->scene == 9)) {
        sfMusic_stop(g->music.music[2]);
        sfMusic_stop(g->music.music[1]);
        quit_game(g);
    }
    if (event.key.code == sfKeyT && g->scene == 1)
        add_xp(g, 100);
    event_key_two(g, event);
    if (event.key.code == sfKeyEscape && g->scene == 10)
        g->scene = 0;
}
