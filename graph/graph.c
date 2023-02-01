#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50

// Data structure for a user in the social network
typedef struct
{
  char name[50];
  int  age;
  char gender[10];
  char interests[100];
} User;

// Data structure for a graph
typedef struct
{
  User users[MAX_USERS];
  int  numUsers;
  int  adjacencyMatrix[MAX_USERS][MAX_USERS];
} Graph;

// Function to add a new user to the social network
void addUser(Graph* g, char* name, int age, char* gender, char* interests)
{
  // Check if the maximum number of users has been reached
  if (g->numUsers >= MAX_USERS)
  {
    printf("Error: Maximum number of users reached. Cannot add new user.\n");
    return;
  }

  // Add the new user to the list of users
  int index = g->numUsers;
  strcpy(g->users[index].name, name);
  g->users[index].age = age;
  strcpy(g->users[index].gender, gender);
  strcpy(g->users[index].interests, interests);
  g->numUsers++;
}

// Function to add a connection between two users in the social network
void addConnection(Graph* g, int user1, int user2)
{
  // Check if the users are within bounds
  if (user1 < 0 || user1 >= g->numUsers || user2 < 0 || user2 >= g->numUsers)
  {
    printf("Error: Invalid user. Cannot add connection.\n");
    return;
  }

  // Add the connection to the adjacency matrix
  g->adjacencyMatrix[user1][user2] = 1;
  g->adjacencyMatrix[user2][user1] = 1;
}

// Function to remove a connection between two users in the social network
void removeConnection(Graph* g, int user1, int user2)
{
  // Check if the users are within bounds
  if (user1 < 0 || user1 >= g->numUsers || user2 < 0 || user2 >= g->numUsers)
  {
    printf("Error: Invalid user. Cannot remove connection.\n");
    return;
  }

  // Remove the connection from the adjacency matrix
  g->adjacencyMatrix[user1][user2] = 0;
  g->adjacencyMatrix[user2][user1] = 0;
}

// Function to remove a user from the social network
void removeUser(Graph* g, int user)
{
  // Check if the user is within bounds
  if (user < 0 || user >= g->numUsers)
  {
    printf("Error: Invalid user. Cannot remove user.\n");
    return;
  }

  // Shift all users after the user being removed one position back
  for (int i = user + 1; i < g->numUsers; i++)
  {
    g->users[i - 1] = g->users[i];
  }
  g->numUsers--;

  // Update the adjacency matrix
  for (int i = 0; i < g->numUsers; i++)
  {
    // Shift all connections after the user being removed one position back
    for (int j = user + 1; j < g->numUsers + 1; j++)
    {
      g->adjacencyMatrix[i][j - 1] = g->adjacencyMatrix[i][j];
    }
    // Remove connections to the user being removed
    g->adjacencyMatrix[i][user] = 0;
  }
  for (int i = 0; i < g->numUsers; i++)
  {
    // Shift all connections after the user being removed one position back
    for (int j = user + 1; j < g->numUsers + 1; j++)
    {
      g->adjacencyMatrix[j - 1][i] = g->adjacencyMatrix[j][i];
    }
    // Remove connections from the user being removed
    g->adjacencyMatrix[user][i] = 0;
  }
}

// Function to print the graph
void printGraph(Graph* g)
{
  printf("====================\n");
  printf("Number of users: %d\n", g->numUsers);
  printf("Users:\n");
  for (int i = 0; i < g->numUsers; i++)
  {
    printf("\t%s (age: %d, gender: %s, interests: %s)\n", g->users[i].name,
           g->users[i].age, g->users[i].gender, g->users[i].interests);
  }
  printf("Connections:\n");
  for (int i = 0; i < g->numUsers; i++)
  {
    printf("\t%s is connected to: ", g->users[i].name);
    for (int j = 0; j < g->numUsers; j++)
    {
      if (g->adjacencyMatrix[i][j] == 1)
      {
        printf("%s, ", g->users[j].name);
      }
    }
    printf("\n");
  }
  printf("--------------------\n");
}


int main()
{
  // Create a new graph
  Graph g;
  g.numUsers = 0;

  // Add some users to the social network
  addUser(&g, "Alice", 25, "Female", "Reading, hiking");
  addUser(&g, "Bob", 32, "Male", "Gaming, movies");
  addUser(&g, "Charlie", 29, "Male", "Photography, traveling");
  // addUser(&g, "Donna", 27, "Female", "Cooking, dancing");

  printf("Create a connection\n");
  addConnection(&g, 1, 2);
  printGraph(&g);

  printf("Remove the connection\n");
  removeConnection(&g, 1, 2);
  printGraph(&g);

  printf("Remove an user\n");
  removeUser(&g, 0);
  printGraph(&g);

  printf("Re-do the connection\n");
  addConnection(&g, 0, 1);
  printGraph(&g);
}