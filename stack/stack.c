#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 5

typedef struct
{
  int items[STACK_SIZE];
  int top;
} stack;

bool isFull(stack *s)
{
  if (s->top == STACK_SIZE - 1)
  {
    return true;
  }
  return false;
}

bool isEmpty(stack *s)
{
  if (s->top == -1)
  {
    return true;
  }
  return false;
}

void push(stack *s, int item)
{
  if (isFull(s))
  {
    printf("Error: stack overflow\n");
  }
  else
  {
    s->items[++s->top] = item;
  }
}

int pop(stack *s)
{
  if (isEmpty(s))
  {
    printf("Error: stack underflow\n");
    return -1;
  }
  else
  {
    return s->items[s->top--];
  }
}

int peek(stack *s)
{
  if (isEmpty(s))
  {
    printf("Error: stack underflow\n");
    return -1;
  }
  else
  {
    return s->items[s->top];
  }
}

int main(int argc, char **argv)
{
  stack s;
  s.top = -1;

  for (int k = 0; k < STACK_SIZE; k++)
  {
    push(&s, k * 2);
  }

  printf("Popping: %d\n", pop(&s));
  printf("Peeking: %d\n", peek(&s));
  printf("Popping: %d\n", pop(&s));
  printf("Popping: %d\n", pop(&s));
  printf("Popping: %d\n", pop(&s));
  printf("Popping: %d\n", pop(&s));

  return 0;
}
