// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <algorithm>
#include <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::string str;
    std::string value;
    std::ifstream in(filename);
    if (!in) {
        std::cout << "File error!" << std::endl;
    }
    while (!in.eof()) {
        while (true) {
            char temp = in.get();
            if ((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)) value += tolower(temp);
            else
                break;
        }
        tree.adNode(value);
        value = "";
    }
    return tree;
}
