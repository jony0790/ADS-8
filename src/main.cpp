// Copyright 2021 NNTU-CS
#include <iostream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);

int main() {
    BST<std::string> tree;

    makeTree(tree, "warpeace.txt");

    std::cout << "Depth: " << tree.depth() << std::endl;

    return 0;
}
