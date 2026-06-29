
#ifndef MULTITHREADING_HEADER_H
#define MULTITHREADING_HEADER_H

#include <stdbool.h>
typedef enum {
    WRONG_AR_NUMBER = 1,
    WRONG_INPUT = 2,
    MEMORY_ERROR = 3,
    THREAD_ERROR = 4,
    OK = 0
} Results;

//parser.c
//extern Variablen werden in der main gebraucht2
extern int runs;
extern bool activated;
extern int threads;
Results parse(int argc, char *argv[]);

//shared.c
void data_init(bool active);
void data_increment(void);
int data_get_counter(void);
void data_destroy(void);

//utils.c
void *worker_run(void *arg);
void print_error(Results result);
double get_time_seconds(void);

#endif //MULTITHREADING_HEADER_H