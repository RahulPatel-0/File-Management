#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char name[20];
  int size;
  char type[20];
  struct node *left, *right;
};

struct node *root = NULL;

struct node* createNode(char name[20], int size, char type[20]){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  strcpy(newnode->name, name);
  newnode->size = size;
  strcpy(newnode->type, type);
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

struct node* insertNode(struct node *node, char name[20], int size, char type[20]){
  if (node == NULL)
    return createNode(name, size, type);
  else if (strcmp(name, node->name) < 0)
    node->left = insertNode(node->left, name, size, type);
  else if (strcmp(name, node->name) > 0)
    node->right = insertNode(node->right, name, size, type);
  return node;
}

void inOrderTraversal(struct node *node){
  if (node == NULL)
    return;
  inOrderTraversal(node->left);
  printf("File Name: %s, File Size: %d, File Type: %s\n", node->name, node->size, node->type);
  inOrderTraversal(node->right);
}

int main(){
  FILE *fp;
  char name[20], type[20];
  int size;
  fp = fopen("file.txt", "r");
  while (fscanf(fp, "%s %d %s", name, &size, type) == 3){
    root = insertNode(root, name, size, type);
  }
  fclose(fp);
  printf("InOrder Traversal:\n");
  inOrderTraversal(root);
  return 0;
}