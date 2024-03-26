#include "parsing.h"
#include "tasks.h"

int main(int argc, char** argv)
{
    Arguments args =  ParseArgs(argc, argv);

    TaskList tasklist = {0, NULL};
    LoadTasks(&tasklist);

    if (args.aFlag == 1 && (args.aFlag + args.rFlag <= 1))
    {
        AddTask(&tasklist, args.taskDesc);
        WriteTasks(&tasklist);
    }
    else if (args.rFlag == 1 && (args.aFlag + args.rFlag <= 1))
    {
        RemoveTask(&tasklist, args.rTarget);
        WriteTasks(&tasklist);
    }
    else if (args.aFlag + args.rFlag > 1)
    {
      fprintf(stderr, "TOUDOU: Please use only one option at a time\n");
      return 1;
    }
    else if (args.aFlag + args.rFlag == 0)
    {
      PrintTaskList(&tasklist);
    }

    free(tasklist.ptrList);

    return 0;
}
