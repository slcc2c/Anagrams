#include <iostream>
#include "ATNode.h"

using namespace std;
int main() {
    string word = "abc";

    ATNode root = ATNode(word, 0);

    std::cout << root.children[1].letter << endl;
    return 0;
}