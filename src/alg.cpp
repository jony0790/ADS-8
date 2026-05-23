// Copyright 2021 NNTU-CS
// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <cctype>
#include  <string>
#include  "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "File error!" << std::endl;
        return;
    }

    std::string word;
    char ch;

    while (file.get(ch)) {
        // faqat latin harflarni olish
        if (isalpha(static_cast<unsigned char>(ch))) {
            // kichik harfga o'tkazish
            word += static_cast<char>(tolower(ch));
        } else {
            // so'z tugadi
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }

    // oxirgi so'zni qo'shish
    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
}
