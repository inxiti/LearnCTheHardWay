#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count)
{
	int i = 0;

	for(i = 0; i < count; i++) {
		to[i] = from[i];
	}

	return i;
}

int duffs_device(char *from, char *to, int count)
{
	return count;
}

int zeds_device(char *from, char *to, int count)
{
	return count;
}

int valid_copy(char *data, int count, char expects)
{
	int i = 0;

	for(i = 0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[]) {


	return 0;
}
