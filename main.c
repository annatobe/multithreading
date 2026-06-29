#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <pthread.h>

#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char *argv[]){
    Results result = parse(argc, argv);
    if (result!= OK)
    {
        print_error(result);
        return result;
    }

    //Initialisiert den Zaehler und wenn aktiv den Mutex
    data_init(activated);

    //Speicher fuer alle Thread-IDs werden reserviert
    pthread_t *thread_ids = malloc(sizeof(pthread_t) * threads);
    if (!thread_ids)
    {
        data_destroy();
        print_error(MEMORY_ERROR);
        return MEMORY_ERROR;
    }

    //misst Zeit nach Beendigung der Threads
    double start =get_time_seconds();

    //erstellt Threads
    for (int i = 0; i < threads; i++)
    {
        //ID wird in thread_ids[i] gespeichert, keine besonderen Einstellungen, Thread soll worker_run ausfuehren, kein Argument an worker_run uebergeben
        if (pthread_create(&thread_ids[i], NULL, worker_run, NULL) != 0)
        {
            data_destroy();
            free(thread_ids);
            print_error(THREAD_ERROR);
            return THREAD_ERROR;
        }
    }

    //main wartet auf alle gestarteten Threads
    for (int i = 0; i < threads; i++)
    {
        pthread_join(thread_ids[i], NULL);
    }

    //Misst Zeit nach Threaderstellung
    double end =get_time_seconds();
    //berechnet Ausfuehrungszeit der Threads
    double duration = end - start;
    //aktueller Zaehlerstand
    int actual_counter = data_get_counter();
    //erwarteter Zaehlerstand ohne verlorene Inkrementierunge
    int expected_counter = threads * runs;

    printf("Threads: %d\n", threads);
    printf("Runs pro Thread: %d\n", runs);
    if (activated)
    {
        printf("Synchronisation: Mutex\n");
    }
    else
    {
        printf("Keine Synchronisation\n");
    }
    printf("Erwartete Durchlaeufe: %d\n", expected_counter);
    printf("Tatsaechliche Durchlaeufe: %d\n", actual_counter);
    printf("Ausfuehrungsdauer: %lf\n", duration);

    if (actual_counter == expected_counter)
    {
        printf("Ergebnis: korrekt\n");
    }
    else
    {
        printf("Ergebnis: falsch / Race Condition sichtbar\n");
    }

    free(thread_ids);
    data_destroy();


    return 0;
}