#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define INCREMENT 1000000
#define THREAD_COUNT 4

static long long compteur_global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* incrementeur_thread(void* arg) {
    (void)arg;
    for (int i = 0; i < INCREMENT; i++) {
        pthread_mutex_lock(&mutex);  
        compteur_global++; 
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void) {
    printf("=== Compteur Sécurisé ===\n");
    long long expected = (long long)INCREMENT * THREAD_COUNT;

    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++)
        pthread_create(&threads[i], NULL, incrementeur_thread, NULL);

    for (int i = 0; i < THREAD_COUNT; i++)
        pthread_join(threads[i], NULL);

    printf("Valeur attendue : %lld\n", expected);
    printf("Résultat final : %lld\n", compteur_global);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}
