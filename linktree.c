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

    return treenode;
}

void Preorder(TreeNode* T) {
    if (T == NULL) {
        return;
    }

    printf("%d\n", T->data);
    Preorder(T->left);
    Preorder(T->right);
}

void Postorder(TreeNode* T) {
    if (T == NULL) {
        return;
    }

    Postorder(T->left);
    Postorder(T->right);
    printf("%d\n", T->data);
}

void Inorder(TreeNode* T) {
    if (T == NULL) {
        return;
    }

    Inorder(T->left);
    printf("%d\n", T->data);
    Inorder(T->right);
}

int depth(TreeNode* root, int current_depth, int max_depth) {


    if (root == NULL) {
        return max_depth;
    }

    if (current_depth > max_depth) {
        max_depth = current_depth;
    }

    max_depth = depth(root->left, current_depth + 1, max_depth);
    max_depth = depth(root->right, current_depth + 1, max_depth);

    return max_depth;
}

typedef struct Stack {
    TreeNode** arr;                                        //arr为存放TreeNode*类型指针的数组
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));
    stack->arr = malloc(sizeof(TreeNode*) * capacity);    //申请的内存大小为单个指针内存乘数量
    stack->top = -1;                                      //代表栈顶，-1时表示栈中无元素
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;                              //判断是否空栈
}

void push(Stack* stack, TreeNode* node) {
    if (stack->top == stack->capacity - 1) {              //判断是否满栈（数组下标由零开始）
        return;
    }
    stack->arr[++stack->top] = node;                      //入栈，先移动栈顶，再存入节点
}

TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) {                                 //若无节点，则结束
        return NULL;
    }
    return stack->arr[stack->top--];                      //出栈，先返回节点，再移动栈顶
}

void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    Stack* stack = createStack(100);

    push(stack, root);

    while (!isEmpty(stack)) {
        TreeNode* node = pop(stack);

        printf("%d", node->data);

        if (node->right != NULL) {
            push(stack, node->right);
        }
        if (node->left != NULL) {
            push(stack, node->left);
        }
    }

    free(stack->arr);
    free(stack);
}



int main() {
    TreeNode* root = create_node(1);
    TreeNode* node2 = create_node(2);
    TreeNode* node3 = create_node(3);
    TreeNode* node4 = create_node(4);
    TreeNode* node5 = create_node(5);
    TreeNode* node6 = create_node(6);
    TreeNode* node7 = create_node(7);

    root->left = node2;
    node2->left = node4;
    node2->right = node5;
    root->right = node3;
    node3->left = node6;
    node3->right = node7;

    preorderTraversal(root);


    /*  Preorder(root);
      printf("\n");
      Inorder(root);
      printf("\n");
      Postorder(root);

      int result = depth(root, 1, 0);
      printf("The max depth of the tree is %d\n", result);*/

    return 0;
}