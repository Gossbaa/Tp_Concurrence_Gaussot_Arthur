#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define TAILLE_BUFFER 5

// Buffer circulaire
static int buffer[TAILLE_BUFFER];
static int index_prod = 0;
static int index_cons = 0;


// Le deuxième paramètre `0` signifie "partagé entre threads du même processus" (vs `1` pour inter-processus).

static sem_t places_libres;
static sem_t elements_disponibles;  
static sem_t mutex_buffer; // Qulle est le soucis ici ?
