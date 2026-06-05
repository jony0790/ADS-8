// Copyright 2026

#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>

template <class T>
class BST {
 private:
    struct Node {
        T key;
        int freq;
        Node* left;
        Node* right;

        explicit Node(const T& k)
            : key(k), freq(1), left(nullptr), right(nullptr) {
        }
    };

    Node* root;

    void insert(Node** node, const T& key) {
        if (*node == nullptr) {
            *node = new Node(key);
            return;
        }

        if (key < (*node)->key) {
            insert(&((*node)->left), key);
        } else if (key > (*node)->key) {
            insert(&((*node)->right), key);
        } else {
            (*node)->freq++;
        }
    }

    int search(Node* node, const T& key) const {
        if (node == nullptr)
            return 0;

        if (key < node->key)
            return search(node->left, key);

        if (key > node->key)
            return search(node->right, key);

        return node->freq;
    }

    int depth(Node* node) const {
        if (node == nullptr)
            return 0;

        int l = depth(node->left);
        int r = depth(node->right);

        return (l > r ? l : r) + 1;
    }

 public:
    BST()
        : root(nullptr) {
    }

    void insert(const T& key) {
        insert(&root, key);
    }

    int search(const T& key) const {
        return search(root, key);
    }

    int depth() const {
        return depth(root);
    }
};

#endif  // INCLUDE_BST_H_
