#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *create_node(int data);
void preorder(const TreeNode *root);
void inorder(const TreeNode *root);
void postorder(const TreeNode *root);
void destroy(TreeNode *root);

#endif //BINARY_TREE_H
