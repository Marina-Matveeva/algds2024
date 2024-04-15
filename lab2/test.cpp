#include "pch.h"
#include "../DataDesign2/Lab2.c"

TEST(CreateNode, Create_node) {
    struct Node* root = Create_Node(5);

    EXPECT_EQ(root->data, 5);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);

    free(root);
}

TEST(InsertNode, Insert_node) {
    struct Node* root = NULL;
    root = Insert_Node(root, 5);
    Insert_Node(root, 2);
    Insert_Node(root, 6);

    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, 5);
    EXPECT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->data, 2);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->data, 6);

    free(root);
}

TEST(Search1, Node_Found) {
    struct Node* root = NULL;
    root = Insert_Node(root, 5);
    root = Insert_Node(root, 3);
    root = Insert_Node(root, 7);

    EXPECT_NE(Search(root, 5), nullptr);
}

TEST(Search2, Node_not_Found) {
    struct Node* root = NULL;
    root = Insert_Node(root, 5);
    root = Insert_Node(root, 3);
    root = Insert_Node(root, 7);

    EXPECT_EQ(Search(root, 4), nullptr);
}

TEST(FindMin, Find_min) {
    struct Node* root = NULL;
    root = Insert_Node(root, 6);
    root = Insert_Node(root, 2);
    root = Insert_Node(root, 8);

    struct Node* minNode = Find_Min(root);

    EXPECT_NE(minNode, nullptr);
    EXPECT_EQ(minNode->data, 2);

    free(root);
    free(minNode);
}

TEST(DeleteNode1, Delete_node) {
    struct Node* root = NULL;
    root = Insert_Node(root, 6);
    root = Insert_Node(root, 2);
    root = Insert_Node(root, 8);

    root = Delete_Node(root, 2);

    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, 6);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->data, 8);

    free(root);
}

TEST(DeleteNode2, Delete_Node_From_Empty_Tree) {
    struct Node* root = NULL;
    root = Delete_Node(root, 2);

    EXPECT_EQ(root, nullptr);

    free(root);
}