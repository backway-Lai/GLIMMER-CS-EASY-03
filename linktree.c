#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                      
    struct TreeNode* left;         
    struct TreeNode* right;         
} TreeNode;

TreeNode* create_node(int value) {
    TreeNode* treenode = malloc(sizeof(TreeNode));

    treenode->data = value;
    treenode->left = NULL;
    treenode->right = NULL;
}

int main() {

}