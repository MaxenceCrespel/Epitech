/*
** EPITECH PROJECT, 2022
** intro_game
** File description:
** rpg
*/

#include "my.h"

void event_intro(game_t *g, sfEvent event)
{
    if (event.type == sfEvtClosed)
        g->reaper.stop = 1;
    if (event.type == sfEvtKeyPressed) {
        event_intro2(g, event);
    }
    event_intro3(g, event);
}

void change_rect_reaper(game_t *g)
{
    static int i = 0;
    sfIntRect *rect = malloc(sizeof(sfIntRect) * 5);
    rect[0] = pos_rect(665, 72, 41, 47);
    rect[1] = pos_rect(713, 1, 41, 47);
    rect[2] = pos_rect(713, 43, 41, 47);
    rect[3] = pos_rect(713, 85, 41, 47);
    rect[4] = pos_rect(761, 1, 41, 47);
    sfTime time = sfClock_getElapsedTime(g->reaper.clock);
    if (sfTime_asMilliseconds(time) > 150) {
        sfSprite_setTextureRect(g->reaper.reaper.sprite, rect[i++]);
        sfClock_restart(g->reaper.clock);
    }
    if (i == 5)
        i = 0;
}

void move_reaper(game_t *g)
{
    sfVector2f pos = sfSprite_getPosition(g->reaper.reaper.sprite);
    if (pos.y > 120) {
        change_rect_reaper(g);
        sfSprite_move(g->reaper.reaper.sprite, set_pos(0, -4));
    }
    if (pos.y <= 120 && pos.x >= 180) {
        change_rect_reaper(g);
        sfSprite_move(g->reaper.reaper.sprite, set_pos(-4, 0));
    }
    if (pos.x <= 200)
        g->reaper.next = 2;
}

void intro_game(game_t *g)
{
    create_reaper(g);
    sfEvent event;
    while (g->reaper.stop == 0) {
        sfRenderWindow_display(g->window);
        draw_sprite(g->start.map, g);
        sfRenderWindow_drawSprite(g->window, g->reaper.reaper.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->start.perso.sprite.sprite,
        NULL);
        if (g->writer.status == 0) {
            animate_text(g, TALK_FR[g->reaper.next]);
        }
        sfRenderWindow_drawText(g->window, g->writer.text.text, NULL);
        while (sfRenderWindow_pollEvent(g->window, &event))
            event_intro(g, event);
        if (g->reaper.next == 2)
            move_reaper(g);
    }
    g->reaper.stop = 0;
    sfSprite_setPosition(g->reaper.reaper.sprite, set_pos(180, 120));
}
