#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Funktion die von jedem Thread ausgefuehrt wird
//jeder Thread erhoeht Zaehler runs-mal
void *worker_run(void *arg){

    (void)arg;
    for (long long i = 0; i < runs; i++)
    {
        data_increment();
    }
    return NULL;
}
//misst die aktuelle Zeit inn Sekunden
double get_time_seconds(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    return ts.tv_sec + ts.tv_nsec / 1000000000.0;
}//gibt den Fehlercode aus
void print_error(Results result)
{
    if (result == WRONG_AR_NUMBER)
    {
        fprintf(stderr, "zu wenige oder zu viele Argumente eingegebn\n");
    }
    else if (result == WRONG_INPUT)
    {
        fprintf(stderr, "Fehlerhafte Eingabe\n");
    }
    else if (result == MEMORY_ERROR)
    {
        fprintf(stderr, "Fehler bei der Speicherreservierung\n");
    }
    else if (result == THREAD_ERROR)
    {
        fprintf(stderr, "Fehler beim Erstellen eines Threads\n");
    }
}
