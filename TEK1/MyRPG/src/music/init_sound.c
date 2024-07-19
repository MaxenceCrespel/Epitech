/*
** EPITECH PROJECT, 2022
** init_sound.c
** File description:
** function to init sound.
*/

#include "my.h"

void ft_soundbuffer_two(game_t *g)
{
    g->sound.buffer[8] =
    sfSoundBuffer_createFromFile("assets/sfx/power_up.ogg");
    g->sound.buffer[9] = sfSoundBuffer_createFromFile("assets/sfx/click.ogg");
    g->sound.buffer[10] = sfSoundBuffer_createFromFile("assets/sfx/game.ogg");
    g->sound.buffer[11] =
    sfSoundBuffer_createFromFile("assets/sfx/power_up2.ogg");
    g->sound.buffer[12] = sfSoundBuffer_createFromFile("assets/sfx/slash.ogg");
    g->sound.buffer[13] =
    sfSoundBuffer_createFromFile("assets/sfx/hplose.ogg");
    g->sound.buffer[14] = sfSoundBuffer_createFromFile("assets/sfx/gem.ogg");
    g->sound.buffer[15] = sfSoundBuffer_createFromFile("assets/sfx/magic.ogg");
    g->sound.buffer[16] = NULL;
}

int ft_soundbuffer(game_t *g)
{
    g->sound.buffer[0] = sfSoundBuffer_createFromFile("assets/sfx/intro.ogg");
    g->sound.buffer[1] = sfSoundBuffer_createFromFile("assets/sfx/hit.ogg");
    g->sound.buffer[2] = sfSoundBuffer_createFromFile("assets/sfx/knife.ogg");
    g->sound.buffer[3] =
    sfSoundBuffer_createFromFile("assets/sfx/level_up.ogg");
    g->sound.buffer[4] = sfSoundBuffer_createFromFile("assets/sfx/lose.ogg");
    g->sound.buffer[5] = sfSoundBuffer_createFromFile("assets/sfx/lowhp.ogg");
    g->sound.buffer[6] =
    sfSoundBuffer_createFromFile("assets/sfx/pause_in.ogg");
    g->sound.buffer[7] =
    sfSoundBuffer_createFromFile("assets/sfx/pause_out.ogg");
    ft_soundbuffer_two(g);
    return (0);
}

int ft_sound(game_t *g)
{
    g->sound.sound[0] = sfSound_create();
    g->sound.sound[1] = sfSound_create();
    g->sound.sound[2] = sfSound_create();
    g->sound.sound[3] = sfSound_create();
    g->sound.sound[4] = sfSound_create();
    g->sound.sound[5] = sfSound_create();
    g->sound.sound[6] = sfSound_create();
    g->sound.sound[7] = sfSound_create();
    g->sound.sound[8] = sfSound_create();
    g->sound.sound[9] = sfSound_create();
    g->sound.sound[10] = sfSound_create();
    g->sound.sound[11] = sfSound_create();
    g->sound.sound[12] = sfSound_create();
    g->sound.sound[13] = sfSound_create();
    g->sound.sound[14] = sfSound_create();
    g->sound.sound[15] = sfSound_create();
    g->sound.sound[16] = NULL;
    return (0);
}

int init_sound(game_t *g)
{
    g->sound.sound = malloc(sizeof(sfSound *) * 17);
    g->sound.buffer = malloc(sizeof(sfSoundBuffer *) * 17);

    if (g->sound.sound == NULL || g->sound.buffer == NULL)
        return (84);
    ft_soundbuffer(g);
    ft_sound(g);
    g->sound.status = 0;
    return (0);
}

int ft_setbuffer(game_t *g)
{
    sfSound_setBuffer(g->sound.sound[0], g->sound.buffer[0]);
    sfSound_setBuffer(g->sound.sound[1], g->sound.buffer[1]);
    sfSound_setBuffer(g->sound.sound[2], g->sound.buffer[2]);
    sfSound_setBuffer(g->sound.sound[3], g->sound.buffer[3]);
    sfSound_setBuffer(g->sound.sound[4], g->sound.buffer[4]);
    sfSound_setBuffer(g->sound.sound[5], g->sound.buffer[5]);
    sfSound_setBuffer(g->sound.sound[6], g->sound.buffer[6]);
    sfSound_setBuffer(g->sound.sound[7], g->sound.buffer[7]);
    sfSound_setBuffer(g->sound.sound[8], g->sound.buffer[8]);
    sfSound_setBuffer(g->sound.sound[9], g->sound.buffer[9]);
    sfSound_setBuffer(g->sound.sound[10], g->sound.buffer[10]);
    sfSound_setBuffer(g->sound.sound[11], g->sound.buffer[11]);
    sfSound_setBuffer(g->sound.sound[12], g->sound.buffer[12]);
    sfSound_setBuffer(g->sound.sound[13], g->sound.buffer[13]);
    sfSound_setBuffer(g->sound.sound[14], g->sound.buffer[14]);
    sfSound_setBuffer(g->sound.sound[15], g->sound.buffer[15]);
    return (0);
}
