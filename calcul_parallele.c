#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

#define TAILLE_DONNEES 10
#define MULTIPLICATEUR 1000

static const int DONNEES[TAILLE_DONNEES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

typedef struct {
    int valeur;
    int multiplicateur;
} args_t;

void* calcul_thread(void* arg) {
    thread_args_t* args = (thread_args_t*)arg;
    int local_res = 0;

    for (int j = 0; j < MULTIPLICATEUR; j++) {
        local_res += args->valeur * args->valeur + args->valeur;
        usleep(20);
    }
    
    args->resultat = local_res;
    return NULL;
}

int main(void) {

    printf("=== Calcul Parallèle ===\n");

    struct timespec debut, fin;
    clock_gettime(CLOCK_MONOTONIC, &debut);

    pthread_t threads[TAILLE_DONNEES];
    thread_args_t args[TAILLE_DONNEES];
    int somme = 0;

    
    for (int i = 0; i < TAILLE_DONNEES; i++) {
        args[i].valeur = DONNEES[i];
        args[i].resultat = 0;
        if (pthread_create(&threads[i], NULL, calcul_thread, &args[i]) != 0) {
            perror("Erreur lors de la création du thread");
            return 1;
        }
    }

    
    for (int i = 0; i < TAILLE_DONNEES; i++) {
        pthread_join(threads[i], NULL);
        somme += args[i].resultat;
        printf("Thread %d terminé, le résultat est : %ld\n", i, args[i].resultat);
    }

        

    clock_gettime(CLOCK_MONOTONIC, &fin);
    long duree = (fin.tv_sec - debut.tv_sec) * 1000 + 
                 (fin.tv_nsec - debut.tv_nsec) / 1000000;

    printf("Résultat total : %ld\n", somme);
    printf("Durée : %ld ms\n", duree);

    return 0;
}