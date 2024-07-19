/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-panoramix-maxence.crespel
** File description:
** main
*/

#include "../include/panoramix.h"

ressources_t *ressources = NULL;
sem_t sem_villager_druid;
sem_t sem_refill_needed;
pthread_mutex_t lock;

void initialize_all(char **av)
{
    sem_init(&sem_villager_druid, 0, 0);
    sem_init(&sem_refill_needed, 0, 0);
    ressources = malloc(sizeof(ressources_t));
    ressources->villagers = atoi(av[1]);
    ressources->pot_size = atoi(av[2]);
    ressources->pot_remain = ressources->pot_size;
    ressources->fights = atoi(av[3]);
    ressources->refills = atoi(av[4]);
    pthread_mutex_init(&lock, NULL);
}

void create_threads(pthread_t *threads)
{
    int rc;
    int i;

    for (i = 0; i < ressources->villagers; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        rc = pthread_create(&threads[i], NULL, villager, a);
    }
}

void join_threads(pthread_t *threads)
{
    int rc;
    int i;

    for (i = 0; i < ressources->villagers; i++)
        rc = pthread_join(threads[i], NULL);
}

void cancel_druid(pthread_t druid_thread)
{
    pthread_cancel(druid_thread);
    pthread_join(druid_thread, NULL);
}

int main(int ac, char **av)
{
    pthread_t *threads;
    pthread_t druid_thread;

    if (ac != 5 || atoi(av[1]) < 0 || atoi(av[2]) < 0 || atoi(av[3]) < 0 || atoi(av[4]) < 0)
        return 84;
    initialize_all(av);
    threads = malloc(sizeof(pthread_t) * (ressources->villagers + 1));
    pthread_create(&druid_thread, NULL, druid, NULL);
    create_threads(threads);
    join_threads(threads);
    cancel_druid(druid_thread);
    return 0;
}
