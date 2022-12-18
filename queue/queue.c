#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// queue data structure
struct Queue
{
  int data[MAX_SIZE];
  int front, rear;
  int size;
};

struct Queue* createQueue()
{
  struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
  q->front        = 0;
  q->rear         = -1;
  q->size         = 0;
  return q;
}

int isEmpty(struct Queue* q)
{
  return (q->size == 0);
}

int isFull(struct Queue* q)
{
  return (q->size == MAX_SIZE);
}

void enqueue(struct Queue* q, int value)
{
  if (!isFull(q))
  {
    q->rear          = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
  }
}

int dequeue(struct Queue* q)
{
  if (!isEmpty(q))
  {
    int value = q->data[q->front];
    q->front  = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
  }
}

int peek(struct Queue* q)
{
  if (!isEmpty(q))
  {
    return q->data[q->front];
  }
}

int size(struct Queue* q)
{
  return q->size;
}

int main(int argc, char** argv)
{
  struct Queue* q = createQueue();

  for (int k = 0; k < 5; k++)
  {
    enqueue(q, k * 2);
  }

  printf("Dequeue: %d\n", dequeue(q));
  printf("Peeking: %d\n", peek(q));
  printf("Dequeue: %d\n", dequeue(q));
  printf("Dequeue: %d\n", dequeue(q));
  printf("Dequeue: %d\n", dequeue(q));
  printf("Dequeue: %d\n", dequeue(q));

  return 0;
}