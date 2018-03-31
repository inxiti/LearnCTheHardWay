#include <stdio.h>

int main(int argc, char *argv[])
{
    // a list of states for demonstrative purposes
    char *states[] = {
        "California",
        "Oregon",
        "Washington",
        "Texas"};

    // iterate and print all arguments passed to program
    for (int i = 1; i < argc; ++i)
    {
        printf("argument %d: %s\n", i, argv[i]);
    }

    // iterate and print all states in the states array
    for (int i = 0; i < sizeof(states) / sizeof(char *); ++i)
    {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}