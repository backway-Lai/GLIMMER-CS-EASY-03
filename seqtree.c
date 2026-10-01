#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_TREE_SIZE 100

typedef struct {
    int data;
    bool used;
} SeqTreeNode;

typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;

void init_tree(SeqBiTree* tree) {
    int i;
    tree->size = MAX_TREE_SIZE;
    for (i = 0;i < MAX_TREE_SIZE;i++) {
        tree->nodes[i].data = 0;
        tree->nodes[i].used = false;
    }
}

bool set_root(SeqBiTree* tree, int value) {
    tree->nodes[1].data = value;
    tree->nodes[1].used = true;
    
    return true;
}

bool set_left_child(SeqBiTree* tree, int parent_node, int value) {
    tree->nodes[2 * parent_node].data = value;
    tree->nodes[2 * parent_node].used = true;

    return true;
}

bool set_right_child(SeqBiTree* tree, int parent_node, int value) {
    tree->nodes[2 * parent_node + 1].data = value;
    tree->nodes[2 * parent_node + 1].used = true;

    return true;
}

void level_order(SeqBiTree* tree) {
    int last = 0;

    for (int i = 1; i < MAX_TREE_SIZE; i++) {
        if (tree->nodes[i].used == true) {
            last = i;
        }
    }

    for (int i = 1; i <= last; i++) {
        if (tree->nodes[i].used == true) {
            printf("%d ", tree->nodes[i].data);
        }
        else {
            printf("-1 ");
        }
        if ((i & (i + 1)) == 0) {//位与运算，可以比较两数二进制下的位数是否相同，此处用于判断是否换行
            printf("\n");
        }
    }
}

int main() {
    SeqBiTree tree;

    init_tree(&tree);

    set_root(&tree, 1);

    set_left_child(&tree, 1, 2);
    set_right_child(&tree, 1, 3);

    set_left_child(&tree, 2, 4);
    set_right_child(&tree, 2, 5);

    set_left_child(&tree, 3, 6);
    set_right_child(&tree, 3, 7);

    level_order(&tree);

    return 0;
}