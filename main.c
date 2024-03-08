#include <stdio.h>
#include <stdlib.h>

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

int main() {
    return 0;
}
