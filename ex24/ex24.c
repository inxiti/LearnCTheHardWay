// includes
#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_DATA 100

// types
const char *EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Other"
};

typedef enum EyeColor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, OTHER_EYES
} EyeColor;

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
} Person;

// begin
int main() {
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;
	char buffer[MAX_DATA];

	/*
	 * ask important questions to complete profile for user
	 */
	printf("What's your first name? ");
	in = fgets(you.first_name, MAX_DATA-1, stdin);
	check(in != NULL, "Failed to read first name.");

	printf("What's your last name? ");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	check(in != NULL, "Failed to read last name.");

	printf("How old are you? ");
	you.age = atoi(fgets(buffer, MAX_DATA-1, stdin));
	check(you.age > 0, "You have to enter a number.");

	// iterate all eye colors and display the available options
	printf("What color are your eyes:\n");
	for(i = 0; i <= OTHER_EYES; i++) {
		printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	}
	printf("> ");

	int eyes = atoi(fgets(buffer, MAX_DATA-1, stdin));
	check(eyes > 0, "You have to enter a number.");
	you.eyes = eyes - 1;
	check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");

	printf("How much do you make an hour (in USD)? ");
	you.income = atof(fgets(buffer, MAX_DATA-1, stdin));
	check(you.income > 0, "Enter a floating point number, above 0.");

	/*
	 * display results, formatted with tabs
	 */
	printf("----- RESULTS -----\n");
	printf("First Name: \t%s", you.first_name);
	printf("Last Name: \t%s", you.last_name);
	printf("Age: \t\t%d\n", you.age);
	printf("Eyes: \t\t%s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: \t$%.2f/hour\n", you.income);

	return 0;

error:
	return -1;
}
