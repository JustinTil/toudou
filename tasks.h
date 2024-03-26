#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task
{
    char desc[256];
}Task;

typedef struct TaskList
{
    int n;
    Task* ptrList;
}TaskList;


int LoadTasks(TaskList* ts);
int WriteTasks(TaskList* ts);
void PrintTaskList(TaskList* ts);
void AddTask(TaskList* ts, char* desc);
void RemoveTask(TaskList* ts, int taskID);


// Debugging
int QuickWriteBinary(int n);

#endif