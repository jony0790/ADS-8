// Copyright 2021 NNTU-CS

#include <string>

template <typename T>
class BST {
 private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;

        Node(const T& value) {
            key = value;
            count = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    Node* insert(Node* node, const T& value) {
        if (node == nullptr)
            return new Node(value);

        if (value == node->key) {
            node->count++;
        } else if (value < node->key) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    int depth(Node* node) {
        if (node == nullptr)
            return 0;

        int l = depth(node->left);
        int r = depth(node->right);

        return 1 + (l > r ? l : r);
    }

    bool search(Node* node, const T& value) {
        if (node == nullptr)
            return false;

        if (node->key == value)
            return true;

        if (value < node->key)
            return search(node->left, value);

        return search(node->right, value);
    }

 public:
    BST() {
        root = nullptr;
    }

    void insert(const T& value) {
        root = insert(root, value);
    }

    int depth() {
        return depth(root);
    }

    bool search(T value) {
        return search(root, value);
    }
};
