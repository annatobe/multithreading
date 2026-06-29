#include "header.h"
#include <stdbool.h>
#include <pthread.h>

static pthread_mutex_t mutex;
static long long counter;
static bool use_mutex = false;//initialis
void data_init(bool active)
{
    counter = 0;
    use_mutex = active;

    if (use_mutex)
    {
        pthread_mutex_init(&mutex, NULL);
    }

}

void data_increment(void)
{
    if (use_mutex)
    {
        pthread_mutex_lock(&mutex);
    }
    counter++;
    if (use_mutex)
    {
        pthread_mutex_unlock(&mutex);
    }
}

long long data_get_counter(void)
{
    return counter;
}

void data_destroy(void)
{
    if (use_mutex)
    {
        pthread_mutex_destroy(&mutex);
    }

}