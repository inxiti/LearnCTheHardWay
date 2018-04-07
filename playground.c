/*
    for testing purposes only

    whenever i want to experiment, i'll try it here.

    (*func)(arg)

    get the value at(*) func, since it is a function it expects an argument,
    so pass it an argument in its invocation.

    (*func) gets the value at the spot in memory that is pointed at, it's a
    function.

    value-at-func-function(arg) is essentially what happens, a normal
    function call.
 */

// includes
#include <stdio.h>

// functions
void
func(int (*printer)(char*), char* str)
{
  // invoke the pointed to function with the appropriate argument
  if ((*printer)(str) == 0) {
    printf("Message printed successfully.\n\n");
  } else {
    printf("Message printed unsuccessfully.\n\n");
  }
}

int
print_message(char* str)
{
  printf("Printing message: %s\n", str);

  return 0;
}

void
func2(int* param)
{
  printf("param's pointed to address is: %p\n", (void*)param);

  // *param actually is the value of x, changing it also changes x, it's the
  // places in memory.
  *param = 22222;
}

// main
int
main()
{
  char* str = "Hello, world.";

  // pass a function and a string to func
  func(&print_message, str);

  int x = 11111;
  int* ptr = &x;

  // showing addresses
  printf("ptr addy is  : %p\n", (void*)&ptr); // pass address of ptr itself
  printf("ptr points to: %p\n", (void*)ptr);
  printf("x address is : %p\n", (void*)&x);

  // before and after values, demonstrating the memory is the same
  printf("\nx before: %d\n", *ptr);
  func2(ptr);
  printf("x after : %d\n", *ptr);

  return 0;
}