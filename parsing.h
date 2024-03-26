#ifndef PARSING_H
#define PARSING_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

typedef struct Arguments
{
    // Add a task to the list
    int aFlag;
    char* taskDesc;

    // Remove a task from the list
    int rFlag;
    int rTarget;
}Arguments;

Arguments ParseArgs(int argc, char** argv);

// Debugging
void PrintArgs(Arguments args);

#endif