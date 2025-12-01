#include "include/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *create_node(int data) {
  TreeNode *new_node = (TreeNode *) malloc(sizeof(TreeNode));

  if (new_node == NULL) {
    printf("Binary Tree Error: Failed to allocate memory\n");
    return NULL;
  }

  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

void preorder(const TreeNode *root) {
  if (root != NULL) {
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(const TreeNode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
  }
}

void postorder(const TreeNode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
  }
}

void destroy(TreeNode *root) {
  if (root == NULL) return;
  destroy(root->left);
  destroy(root->right);
  free(root);
}
