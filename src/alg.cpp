// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include <string>
#include <algorithm>
using namespace  std;

BST<string> makeTree(const char* filename) {
  BST<string> tree;
    string str;
    string value;
    ifstream in(filename);
    if (!in) {
        cout << "File error!" << endl;
    }
    while (!in.eof()) {
        while (true) {
            char temp = in.get();
            if ((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)) value += tolower(temp);
            else
                break;
        }
        tree.adNode_(value);
        value = "";
    }
    return tree;
}
