#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LoadTasks(TaskList* ts)
{
    char* filename = "/usr/local/bin/toudoutasks";
    FILE* fs = NULL;
    int n;

    if ((fs = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Could not read file \"%s\" while reading\n", filename);
        return 1;
    }

    fread(&n, sizeof(int), 1, fs);

    ts->n = n;
    ts->ptrList = (Task*)malloc(sizeof(Task) * ts->n);

    fread(ts->ptrList, sizeof(Task), ts->n, fs);

    // Debugging
    //printf("dbg LoadTasks: n = %d\n", n);
    
    fclose(fs);
    return 0;
}

int WriteTasks(TaskList* ts)
{
    char* filename = "/usr/local/bin/toudoutasks";
    FILE* fs = NULL;

    if ((fs = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open file \"%s\" while writing\n", filename);
        return 1;
    }

    fwrite(&ts->n, sizeof(int), 1, fs);
    fwrite(ts->ptrList, sizeof(Task), ts->n, fs);

    fclose(fs);
    return 0;
}

void PrintTaskList(TaskList* ts)
{
    printf("TOUDOU:\n");

    for (int i = 0; i < ts->n; i++)
    {
        printf("  [%d] %s\n", i + 1, (ts->ptrList + i)->desc);
    }
}

void AddTask(TaskList* ts, char* desc)
{
    ts->n += 1;
    ts->ptrList = (Task*)realloc(ts->ptrList, sizeof(Task) * ts->n);

    strcpy((ts->ptrList + (ts->n - 1))->desc, desc);
}

void RemoveTask(TaskList* ts, int taskID)
{
    int rmIndex = taskID - 1;
    for (int i = rmIndex; i < (ts->n - 1); i++)
    {
        strcpy((ts->ptrList + i)->desc, (ts->ptrList + i + 1)->desc);
    }

    ts->n -= 1;
    ts->ptrList = (Task*)realloc(ts->ptrList, sizeof(Task) * ts->n);
}

// Debugging
int QuickWriteBinary(int n)
{
    FILE* fs;
    char* filename = "toudoutasks";

    if ((fs = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "Could not read file \"%s\"\n", filename);
        abort();
    }

    fwrite(&n, sizeof(int), 1, fs);

    fclose(fs);
    return 0;
}