#pragma once

struct Node;
struct Node* Create_Node(int value);
struct Node* Insert_Node(struct Node* root, int value);
struct Node* Search(struct Node* root, int value);
struct Node* Find_Min(struct Node* node);
struct Node* Delete_Node(struct Node* root, int value);