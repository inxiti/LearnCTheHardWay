#include <stdio.h>
#include <dlfcn.h>
#include "dbg.h"

typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[])
{
	int rc = 0;
	check(argc == 4, "USAGE: ex20 libex29.so function data");

	return 0;

error:
	return 1;
}
