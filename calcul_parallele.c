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

    s
    clock_gettime(CLOCK_MONOTONIC, &fin);
    long duree = (fin.tv_sec - debut.tv_sec) * 1000 + 
                 (fin.tv_nsec - debut.tv_nsec) / 1000000;

    printf("Résultat total : %ld\n", somme_total);
    printf("Durée : %ld ms\n", duree);

    return 0;
}