// Copyright 2026

#include <cctype>
#include <fstream>
#include <string>

#include "../include/bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);

    if (!file)
        return;

    std::string word;
    char ch;

    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += static_cast<char>(
                std::tolower(static_cast<unsigned char>(ch)));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }

    if (!word.empty())
        tree.insert(word);

    file.close();
}
