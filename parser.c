//
// Created by root on 6/29/26.
//
#include "header.h"
#include <stdbool.h>
#include <stdlib.h>
char *program;
int threads;
long long runs;
int active;
bool activated; //0 nicht geschuetzt, 1 geschuetzt

//Zerteilt die Eingabe in ihre Argumente
Results parse(int argc, char *argv[])
{
    if (argc != 4)
    {
        return WRONG_AR_NUMBER;
    }
    program = argv[0];
    threads = atoll(argv[1]);
    runs = atoll(argv[2]);
    active = atoll(argv[3]);
    if (active== 1)
    {
        activated = true;
    }
    else if (active == 0)
    {
        activated = false;
    }
    else
    {
        return WRONG_INPUT;
    }
    if (threads <=0 || runs <= 0)
    {
        return WRONG_INPUT;
    }
    return OK;

}
