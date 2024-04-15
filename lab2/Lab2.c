#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* Create_Node(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* Insert_Node(struct Node* root, int value) {
    if (root == NULL) {
        return Create_Node(value);
    }

    if (value < root->data) {
        root->left = Insert_Node(root->left, value);
    }
    else if (value > root->data) {
        root->right = Insert_Node(root->right, value);
    }
    return root;
}

struct Node* Search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return Search(root->left, value);
    }
    return Search(root->right, value);
}

struct Node* Find_Min(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* Delete_Node(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = Delete_Node(root->left, value);
    }
    else if (value > root->data) {
        root->right = Delete_Node(root->right, value);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = Find_Min(root->right);
        root->data = temp->data;
        root->right = Delete_Node(root->right, temp->data);
    }
    return root;
}
