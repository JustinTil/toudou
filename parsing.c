#include "parsing.h"

Arguments ParseArgs(int argc, char** argv)
{
    Arguments args = {.aFlag = 0, .taskDesc = NULL,
                      .rFlag = 0, .rTarget = 0};
    int c;

    while ((c = getopt(argc, argv, "a:r:")) != -1)
    {
        switch (c) 
        {
            case 'a':
                args.aFlag = 1;
                args.taskDesc = optarg;
                break;
            case 'r':
                args.rFlag = 1;
                if (sscanf(optarg, "%d", &args.rTarget) < 1)
                {
                    fprintf(stderr, "Failed to read a decimal value for -r option's argument\n");
                    abort();
                }
                break;
            case '?':
                if (optopt == 'c')
                {
                    fprintf(stderr, "Option -%c requires an argument\n", optopt);
                }
                else if (isprint(optopt)) 
                {
                    fprintf(stderr, "Unkown option '-%c'.\n", optopt);
                }
                else 
                {
                    fprintf(stderr, "Unknown option charaction '\\x%x'.\n", optopt);
                }
            default:
                abort();
        }
    }

    return args;
}

void PrintArgs(Arguments args)
{
    printf("aFlag = %d, taskDesc = %s\n", args.aFlag, args.taskDesc);
    printf("rFlag = %d, rTarget = %d\n", args.rFlag, args.rTarget);
}
