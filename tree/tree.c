#define binary_tree

#ifdef tree

#elif defined(binary_tree)

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a tree node
struct TreeNode
{
  int              data;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Create a new tree node and return a pointer to it
struct TreeNode *newNode(int data)
{
  struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
  node->data            = data;
  node->left            = NULL;
  node->right           = NULL;
  return node;
}

struct TreeNode *search(struct TreeNode *root, int data)
{
  if (root == NULL || root->data == data)
  {
    return root;
  }

  // Search the left and right subtrees
  struct TreeNode *left = search(root->left, data);
  if (left != NULL)
  {
    return left;
  }
  return search(root->right, data);
}

struct TreeNode *getParent(struct TreeNode *root, struct TreeNode *node)
{
  if (root == NULL || root == node || root->left == node || root->right == node)
  {
    return root;
  }

  // Search the left and right subtrees
  struct TreeNode *left = getParent(root->left, node);
  if (left != NULL)
  {
    return left;
  }
  return getParent(root->right, node);
}


// Traverse the tree in pre-order
void preOrder(struct TreeNode *root)
{
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

int main()
{
  // Create a sample tree
  struct TreeNode *root = newNode(1);
  root->left            = newNode(2);
  root->right           = newNode(3);
  root->left->left      = newNode(4);
  root->left->right     = newNode(5);

  struct TreeNode *search_node = search(root, 4);
  if (search_node != NULL)
  {
    printf("The node I'm searching for has this value: %d\n",
           search_node->data);
    struct TreeNode *parent_node = getParent(root, search_node);
    printf("The node I'm searching for has this parent: %d\n",
           parent_node->data);
  }

  // Traverse the tree in pre-order
  printf("Pre-order traversal: ");
  preOrder(root);
  printf("\n");

  return 0;
}

#endif