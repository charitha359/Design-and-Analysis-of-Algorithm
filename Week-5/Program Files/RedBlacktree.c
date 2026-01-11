#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0
struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};
struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->color = RED;
    n->left = n->right = n->parent = NULL;
    return n;
}
void leftRotate(struct Node **root, struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;

    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}
void rightRotate(struct Node **root, struct Node *y) {
    struct Node *x = y->left;
    y->left = x->right;

    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;

    if (!y->parent)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}
void fixRB(struct Node **root, struct Node *z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node *u = z->parent->parent->right; 
            if (u && u->color == RED) { 
                z->parent->color = BLACK;
                u->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        }
        else {
            struct Node *u = z->parent->parent->left;
            if (u && u->color == RED) {
                z->parent->color = BLACK;
                u->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}
void insert(struct Node **root, int data) {
    struct Node *z = newNode(data);
    struct Node *y = NULL;
    struct Node *x = *root;

    while (x) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (!y)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixRB(root, z);
}
void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d(%c) ", root->data,
               root->color == RED ? 'R' : 'B');
        inorder(root->right);
    }
}
int main() {
    struct Node *root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&root, x);
    }

    printf("\nInorder traversal:\n");
    inorder(root);

    return 0;
}

