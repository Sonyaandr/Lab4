#include <iostream>
#include "Traverse.h"
#include "UI.h"
#include "tests.h"

int main() {
    testTree();
    std::string userChoice;
    help();

    do
    {
        std::getline(std::cin, userChoice);
        std::vector<std::string> words = splitString(userChoice);
        if (userChoice == "menu")
        {
            help();
        }
        else if (words.empty())
        {
            continue;
        }
        else if (userChoice == "quit")
        {
            break;
        }
        else if (words.size() == 2)
        {
            if (words[0] == "int")
            {
                BinaryTree<int> tree;
                treeInterface(tree, words[1]);
            }

            else if (words[0] == "complex")
            {
                BinaryTree<Complex> tree;
                treeInterface(tree, words[1]);
            }
            else
            {
                throw std::invalid_argument("Unknown type");
            }
        }
        else
        {
            throw std::invalid_argument("Unknown command");
        }
    } while (userChoice != "quit");
    return 0;
}