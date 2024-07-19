/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-panoramix-maxence.crespel
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #include <stdlib.h>
    #include <pthread.h>
    #include <stdio.h>
    #include <semaphore.h>

typedef struct ressources_s {
    int villagers;
    int pot_size;
    int fights;
    int refills;
    int pot_remain;
} ressources_t;

extern ressources_t *ressources;
extern sem_t sem_villager_druid;
extern sem_t sem_refill_needed;
extern pthread_mutex_t lock;

// druid.c
void *druid(void *arg);

// main.c
void initialize_all(char **av);
void create_threads(pthread_t *threads);
void join_threads(pthread_t *threads);
void cancel_druid(pthread_t druid_thread);
int main(int ac, char **av);

// villagers.c
void drink(int id);
void need_refill(int id);
void go_sleep(int id);
void handle_villager_action(int id, int fight);
void *villager(void *arg);

#endif /* !PANORAMIX_H_ */
