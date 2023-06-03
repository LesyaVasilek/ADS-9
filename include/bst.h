// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
public:
    struct Node {
        Node* right;
        Node* left;
        T value;
        int counter;
    };

private:
    Node* root;
    Node* adNode(Node* root, T value_element) {
        if (root == nullptr) {
            root = new Node;
            root->value = value_element;
            root->counter = 1;
            root->left = nullptr;
            root->right = nullptr;
        }
        else {
            if (value_element < root->value) root->left = adNode(root->left, value_element);
            else if (value_element > root->value) root->right = adNode(root->right, value_element);
            else
                root->counter++;
        }
        return root;
    }
    int searchNode(Node* root, T value_element) {
        if (root == nullptr) {
            return 0;
        }
        else if (root->value == value_element) {
            return root->counter;
        }
        else if (root->value < value_element) {
            return searchNode(root->right, value_element);
        }
        else {
            return searchNode(root->left, value_element);
        }
    }
    int heightTree(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        else {
            int left1 = heightTree(root->left);
            int right1 = heightTree(root->right);
            if (right1 > left1) {
                return ++right1;
            }
            else {
                return ++left1;
            }
        }
    }

public:
    BST() {
        root = nullptr;
    }
    void addNode_(T value_element) {
        root = addNode(root, value_element);
    }
    int search(T value_element) {
        return searchNode(root, value_element);
    }
    int depth() {
        return heightTree(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
