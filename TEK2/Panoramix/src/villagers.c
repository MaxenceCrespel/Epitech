/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-panoramix-maxence.crespel
** File description:
** villagers
*/

#include "../include/panoramix.h"

void drink(int id)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n", id, ressources->pot_remain);
    pthread_mutex_lock(&lock);
    ressources->pot_remain--;
    pthread_mutex_unlock(&lock);
}

void need_refill(int id)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n", id, ressources->pot_remain);
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
    sem_post(&sem_refill_needed);
    sem_wait(&sem_villager_druid);
}

void go_sleep(int id)
{
    sem_post(&sem_villager_druid);
    printf("Villager %d: I'm going to sleep now.\n", id);
    pthread_exit(NULL);
}

void handle_villager_action(int id, int fight)
{
    sem_wait(&sem_villager_druid);
    if (ressources->pot_remain)
        drink(id);
    else if (ressources->refills)
        need_refill(id);
    else
        go_sleep(id);
    sem_post(&sem_villager_druid);
    printf("Villager %d: Take that roman scum! Only %d left.\n", id, fight);
}

void *villager(void *arg)
{
    int id = *(int*)arg;
    int fight = ressources->fights;

    sem_wait(&sem_villager_druid);
    printf("Villager %d: Going into battle!\n", id);
    sem_post(&sem_villager_druid);
    for (; fight != 0; fight--)
        handle_villager_action(id, fight);
    printf("Villager %d: I'm going to sleep now.\n", id);
    pthread_exit(NULL);
}
