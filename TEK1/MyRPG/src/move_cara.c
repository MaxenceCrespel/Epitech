/*
** EPITECH PROJECT, 2022
** move cara
** File description:
** rpg
*/

#include "my.h"

int can_move(game_t *g, sfVector2f mov)
{
    if (g->start.pos.x - mov.x <= -10200 || g->start.pos.x - mov.x >= 8300
    || g->start.pos.y - mov.y <= -10280 || g->start.pos.y - mov.y >= 9100)
        return 0;
    return 1;
}

void event_move4(game_t *g, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) && can_move(g, set_pos(speed, 0))
    || sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move(g);
        move_map(g, set_pos(speed, 0));
        g->start.r_l = 1;
        g->start.dir = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && can_move(g, set_pos(0, -speed))
    || sfKeyboard_isKeyPressed(sfKeyDown)) {
        move(g);
        move_map(g, set_pos(0, -speed));
        g->start.dir = 2;
    }
}

void event_move3(game_t *g, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) && can_move(g, set_pos(-speed, 0))
    || sfKeyboard_isKeyPressed(sfKeyRight)) {
        move(g);
        move_map(g, set_pos(-speed, 0));
        g->start.dir = 1;
        g->start.r_l = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && can_move(g, set_pos(0, speed))
    || sfKeyboard_isKeyPressed(sfKeyUp)) {
        move(g);
        move_map(g, set_pos(0, speed));
        g->start.dir = 4;
    }
    event_move4(g, speed);
}

void event_move2(game_t *g)
{
    int speed = g->start.perso.ms;
    if (sfKeyboard_isKeyPressed(sfKeyS) && can_move(g, set_pos(-speed, -speed))
    && sfKeyboard_isKeyPressed(sfKeyD)
    || (sfKeyboard_isKeyPressed(sfKeyDown)
    && sfKeyboard_isKeyPressed(sfKeyRight))) {
        move(g);
        move_map(g, set_pos(-speed, -speed));
        g->start.dir = 6;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && can_move(g, set_pos(speed, -speed))
    && sfKeyboard_isKeyPressed(sfKeyQ)
    || (sfKeyboard_isKeyPressed(sfKeyDown)
    && sfKeyboard_isKeyPressed(sfKeyLeft))) {
        move(g);
        move_map(g, set_pos(speed, -speed));
        g->start.dir = 7;
    }
    event_move3(g, speed);
}

void event_move(game_t *g)
{
    int speed = g->start.perso.ms;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && can_move(g, set_pos(-speed, speed))
    && sfKeyboard_isKeyPressed(sfKeyD)
    || (sfKeyboard_isKeyPressed(sfKeyUp)
    && sfKeyboard_isKeyPressed(sfKeyRight))) {
        move(g);
        move_map(g, set_pos(-speed, speed));
        g->start.dir = 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && can_move(g, set_pos(speed, speed))
    && sfKeyboard_isKeyPressed(sfKeyQ)
    || (sfKeyboard_isKeyPressed(sfKeyUp)
    && sfKeyboard_isKeyPressed(sfKeyLeft))) {
        move(g);
        move_map(g, set_pos(speed, speed));
        g->start.dir = 7;
    }
    event_move2(g);
}
