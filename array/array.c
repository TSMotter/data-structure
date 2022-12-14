#include <stdio.h>

#define SIZE 10

int main(int argc, char **argv)
{
  printf("Array Example: \n");

  // Random access:
  int foo[SIZE] = {0};
  foo[3]        = 4;

  // Print the values of the array
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d\n", foo[i]);
  }

  return 0;
}