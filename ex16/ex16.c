#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
  char* name;
  int age;
  int height;
  int weight;
};

struct Person*
Person_create(char* name, int age, int height, int weight)
{
  struct Person* who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void
Person_destroy(struct Person* who)
{
  assert(who != NULL);

  free(who->name); // comment out and check with valgrind
  free(who);
}

void
Person_print(struct Person* who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int
main()
{
  struct Person* joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person* frank = Person_create("Frank Blank", 20, 72, 180);

  printf("Joe is at memory location: %p\n", (void*)joe);
  Person_print(joe);
  printf("\n");

  printf("Frank is at memory location: %p\n", (void*)frank);
  Person_print(frank);
  printf("\nAging twenty years.\n\n");

  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // you must destroy all that you create via malloc
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}
