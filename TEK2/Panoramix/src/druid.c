/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-panoramix-maxence.crespel
** File description:
** druid
*/

#include "../include/panoramix.h"

void *druid(void *arg)
{
    printf("Druid: I'm ready... but sleepy...\n");
    sem_post(&sem_villager_druid);
    while (ressources->refills > 0)
    {
        sem_wait(&sem_refill_needed);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.\n", ressources->refills);
        pthread_mutex_lock(&lock);
        ressources->pot_remain = ressources->pot_size;
        ressources->refills--;
        pthread_mutex_unlock(&lock);
        sem_post(&sem_villager_druid);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_exit(NULL);
}
