#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

// defines the value of THE_SIZE to be 1000, this is it's initial value,
// thus when accessed in ex22_main.c it is 1000 despite not being defined before
// being used there in that file.
int THE_SIZE = 1000;

// global static means file visibility only
static int THE_AGE = 37;

int get_age()
{
    return THE_AGE;
}

void set_age(int age) 
{
    THE_AGE = age;
}

double update_ratio(double new_ratio)
{
    // function scope static means the value is saved even after the function
    // completes it's invocation
    static double ratio = 1.0;

    double old_ratio = ratio;
    ratio = new_ratio;

    return old_ratio;
}

void print_size()
{
    log_info("I think size is: %d", THE_SIZE);
}
