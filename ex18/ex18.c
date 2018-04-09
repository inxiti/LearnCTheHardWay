#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** our old friend die */
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

// typedef creates a fake type, in this case for a function pointer
typedef int (*compare_cb)(int a, int b);

/**
    a classic bubble sort function that uses the compare_cb to do the sorting
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{

}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    }  else {
        return a % b;
    }
}

/**
    used to test that we are sorting things correctly
    by doing the sort, and printing it out
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    
}

int main(int argc, char *argv[]) {


	return 0;
}
