/*
** EPITECH PROJECT, 2022
** ft_music.c
** File description:
** function to play music
*/

#include "my.h"

int init_music(game_t *g)
{
    g->music.music = malloc(sizeof(sfMusic *) * 4);

    if (g->music.music == NULL)
        return (84);
    g->music.music[0] = sfMusic_createFromFile("assets/sfx/music.ogg");
    g->music.music[1] = sfMusic_createFromFile("assets/sfx/game.ogg");
    g->music.music[2] = sfMusic_createFromFile("assets/sfx/boss.ogg");
    g->music.music[3] = NULL;
    g->music.status = 0;
    return (0);
}

int ft_setloop(game_t *g)
{
    sfMusic_setLoop(g->music.music[0], sfTrue);
    sfMusic_setLoop(g->music.music[1], sfTrue);
    sfMusic_setLoop(g->music.music[2], sfTrue);
    sfSound_setLoop(g->sound.sound[0], sfFalse);
    sfSound_setLoop(g->sound.sound[1], sfFalse);
    sfSound_setLoop(g->sound.sound[2], sfFalse);
    sfSound_setLoop(g->sound.sound[3], sfFalse);
    sfSound_setLoop(g->sound.sound[4], sfFalse);
    sfSound_setLoop(g->sound.sound[5], sfFalse);
    sfSound_setLoop(g->sound.sound[6], sfFalse);
    sfSound_setLoop(g->sound.sound[7], sfFalse);
    sfSound_setLoop(g->sound.sound[8], sfFalse);
    sfSound_setLoop(g->sound.sound[9], sfFalse);
    sfSound_setLoop(g->sound.sound[10], sfFalse);
    sfSound_setLoop(g->sound.sound[11], sfFalse);
    sfSound_setLoop(g->sound.sound[12], sfFalse);
    sfSound_setLoop(g->sound.sound[13], sfFalse);
    sfSound_setLoop(g->sound.sound[14], sfFalse);
    sfSound_setLoop(g->sound.sound[15], sfFalse);
    return (0);
}

int init_sfx(game_t *g)
{
    init_music(g);
    init_sound(g);
    ft_setbuffer(g);
    ft_setloop(g);
    return (0);
}

int destroy_sound(game_t *g)
{
    int i = 0;
    int z = 0;

    while (z < 3) {
        sfMusic_destroy(g->music.music[z]);
        z++;
    }
    while (i < 16) {
        sfSound_destroy(g->sound.sound[i]);
        sfSoundBuffer_destroy(g->sound.buffer[i]);
        i++;
    }
    return (0);
}
