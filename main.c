#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* construct_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    if(node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(int value, Node** root) {
    if(value <= (*root)->value) {
        if((*root)->left == NULL) {
            (*root)->left = construct_node(value);
        } else {
            (*root)->left = insert(value, &((*root)->left));
        }
    }
    
    else {
        if((*root)->right == NULL) {
            (*root)->right = construct_node(value);
        } else {
            (*root)->right = insert(value, &((*root)->right));
        }
    }

    return *root;
}

void display_tree(Node* root) {
    if(root != NULL) {
        display_tree(root->left);
        printf("%d\n", root->value);
        display_tree(root->right);
    }
}

void free_memory(Node* root) {
    if(root != NULL) {
        free_memory(root->left);
        free_memory(root->right);
        free(root);
    }
}

int main() {
    const int MAX_VALUE = 10 + 1;
    
    srand(time(0));
    int value_1 = (rand() % MAX_VALUE);
    int value_2 = (rand() % MAX_VALUE);
    int value_3 = (rand() % MAX_VALUE);
    int value_4 = (rand() % MAX_VALUE);
    int value_5 = (rand() % MAX_VALUE);

    Node* node_1 = construct_node(value_1);
    Node* node_2 = insert(value_2, &node_1);
    Node* node_3 = insert(value_3, &node_1);
    Node* node_4 = insert(value_4, &node_1);
    Node* node_5 = insert(value_5, &node_1);

    display_tree(node_1);
    free_memory(node_1);
    
    return 0;
}
