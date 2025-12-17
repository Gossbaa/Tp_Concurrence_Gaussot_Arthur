int main(void) {
    const int NB_TESTS = 50;
    const int NB_THREADS = 9;
    const int NB_INCREMENTS = 1111111;
    const int ATTENDU = NB_THREADS * NB_INCREMENTS;

    printf("=== Test Race Condition ===\n");
    printf("Configuration : %d threads × %d incréments\n", NB_THREADS, NB_INCREMENTS);
    printf("Valeur attendue : %d\n\n", ATTENDU);

    int nb_corrects = 0;
    int min = ATTENDU;
    int max = 0;

    for (int test = 0; test < NB_TESTS; test++) {
        int resultat = executer_test(NB_THREADS, NB_INCREMENTS);

        if (resultat == ATTENDU) {
            nb_corrects++;
            printf("Test %2d : %d v \n", test + 1, resultat);
        } else {
            printf("Test %2d : %d x (différence: %d)\n", test + 1, resultat, ATTENDU - resultat);
        }

        if (resultat < min) min = resultat;
        if (resultat > max) max = resultat;
    }

    printf("\n=== Statistiques ===\n");
    printf("Tests corrects : %d/%d (%.1f%%)\n", 
           nb_corrects, NB_TESTS, (100.0 * nb_corrects) / NB_TESTS);
    printf("Valeur min : %d (perte de %d)\n", min, ATTENDU - min);
    printf("Valeur max : %d\n", max);

    return 0;
}