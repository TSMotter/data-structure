#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes in the linked list
struct node
{
  int          data;
  struct node *next;
};

// Function to create a new node
struct node *create_node(int data)
{
  struct node *new_node = (struct node *) malloc(sizeof(struct node));
  new_node->data        = data;
  new_node->next        = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_node(struct node **head, int data)
{
  struct node *new_node = create_node(data);
  new_node->next        = *head;
  *head                 = new_node;
}

// Function to traverse the list and print the data in each node
void print_list(struct node *head)
{
  struct node *current = head;
  int          size    = 0;
  printf("This is the list: [");
  while (current != NULL)
  {
    printf("%d ", current->data);
    size++;
    current = current->next;
  }
  printf("]. The list size is: %d", size);
  printf("\n");
}

// Function to pop the last element from the list
int pop_last(struct node **head)
{
  if (*head == NULL)
  {
    // The list is empty, so there is nothing to pop
    return -1;
  }
  else if ((*head)->next == NULL)
  {
    // The list has only one element, so we remove it and return its value
    int data = (*head)->data;
    free(*head);
    *head = NULL;
    return data;
  }
  else
  {
    // The list has more than one element, so we traverse the list
    // to find the second-to-last element and remove the last element
    struct node *current = *head;
    while (current->next->next != NULL)
    {
      current = current->next;
    }
    int data = current->next->data;
    free(current->next);
    current->next = NULL;
    return data;
  }
}

// Function to pop the first element from the list
int pop_first(struct node **head)
{
  if (*head == NULL)
  {
    // The list is empty, so there is nothing to pop
    return -1;
  }
  else
  {
    // The list has at least one element, so we remove the first element
    // and return its value
    struct node *first = *head;
    *head              = first->next;
    int data           = first->data;
    free(first);
    return data;
  }
}


int main(int argc, char **argv)
{
  // Create an empty linked list
  struct node *head = NULL;

  // Insert some nodes at the beginning of the list
  print_list(head);

  insert_node(&head, 5);
  insert_node(&head, 10);
  insert_node(&head, 15);
  print_list(head);

  pop_last(&head);
  print_list(head);

  pop_first(&head);
  print_list(head);

  return 0;
}
