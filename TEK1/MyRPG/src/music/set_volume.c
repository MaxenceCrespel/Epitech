/*
** EPITECH PROJECT, 2022
** set_volume.c
** File description:
** function to set volume music/sound.
*/

#include "my.h"

int sound_on(game_t *g)
{
    if (g->sound.status == 0) {
        sfSound_setVolume(g->sound.sound[0], 35);
        sfSound_setVolume(g->sound.sound[1], 35);
        sfSound_setVolume(g->sound.sound[2], 35);
        sfSound_setVolume(g->sound.sound[3], 35);
        sfSound_setVolume(g->sound.sound[4], 35);
        sfSound_setVolume(g->sound.sound[5], 35);
        sfSound_setVolume(g->sound.sound[6], 35);
        sfSound_setVolume(g->sound.sound[7], 35);
        sfSound_setVolume(g->sound.sound[8], 35);
        sfSound_setVolume(g->sound.sound[9], 35);
        sfSound_setVolume(g->sound.sound[10], 35);
        sfSound_setVolume(g->sound.sound[11], 35);
        sfSound_setVolume(g->sound.sound[12], 50);
        sfSound_setVolume(g->sound.sound[13], 35);
        sfSound_setVolume(g->sound.sound[14], 20);
        sfSound_setVolume(g->sound.sound[15], 15);
    }
    return (0);
}

int sound_off(game_t *g)
{
    if (g->sound.status == 1) {
        sfSound_setVolume(g->sound.sound[0], 0);
        sfSound_setVolume(g->sound.sound[1], 0);
        sfSound_setVolume(g->sound.sound[2], 0);
        sfSound_setVolume(g->sound.sound[3], 0);
        sfSound_setVolume(g->sound.sound[4], 0);
        sfSound_setVolume(g->sound.sound[5], 0);
        sfSound_setVolume(g->sound.sound[6], 0);
        sfSound_setVolume(g->sound.sound[7], 0);
        sfSound_setVolume(g->sound.sound[8], 0);
        sfSound_setVolume(g->sound.sound[9], 0);
        sfSound_setVolume(g->sound.sound[10], 0);
        sfSound_setVolume(g->sound.sound[11], 0);
        sfSound_setVolume(g->sound.sound[12], 0);
        sfSound_setVolume(g->sound.sound[13], 0);
        sfSound_setVolume(g->sound.sound[14], 0);
        sfSound_setVolume(g->sound.sound[15], 0);
    }
    return (0);
}

int music_on(game_t *g)
{
    if (g->music.status == 0) {
        sfMusic_setVolume(g->music.music[0], 10);
        sfMusic_setVolume(g->music.music[1], 10);
        sfMusic_setVolume(g->music.music[2], 10);
    }
    return (0);
}

int music_off(game_t *g)
{
    if (g->music.status == 1) {
        sfMusic_setVolume(g->music.music[0], 0);
        sfMusic_setVolume(g->music.music[1], 0);
        sfMusic_setVolume(g->music.music[2], 0);
    }
    return (0);
}

int ft_volume(game_t *g)
{
    sound_on(g);
    sound_off(g);
    music_on(g);
    music_off(g);
    return (0);
}
