#ifndef LAB4_MEPHI_UI_H
#define LAB4_MEPHI_UI_H

#include <vector>
#include <string>
#include <sstream>
#include "Traverse.h"
#include "MapWhereFunctions.h"

void help()
{
    std::cout << "To get this menu type <help>" << std::endl;
    std::cout << "To finish program type <quit>" << std::endl;
    std::cout << "Available functions for tree:" << std::endl;
    std::cout << "print, insert, balance, delete, is_sub_tree, get_sub_tree, find_min, find_max" << std::endl;
    std::cout << "Available traverses for tree:" << std::endl;
    std::cout << "KPL, KLP, LKP, LPK, PKL, PLK" << std::endl;
    std::cout << "Available types of values: int, complex" << std::endl;
    std::cout << "To do action type <type> <function> or <type> <traverse>" << std::endl;
}

std::vector<std::string> splitString(const std::string& str)
{
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

template <typename T>
void printTree(const std::string& prefix, Node<T>* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "L--" );

        std::cout << "(" << node->GetValue() << ")" << std::endl;

        printTree(prefix + (isLeft ? "|   " : "    "), node->GetLeft(), true);
        printTree(prefix + (isLeft ? "|   " : "    "), node->GetRight(), false);
    }
}

template <typename T>
void setTree(BinaryTree<T>& tree)
{
    int amount;
    std::cout << "Enter amount of elements:" << std::endl;
    std::cin >> amount;
    std::cout << "Enter values:" << std::endl;

    for (int i = 0; i < amount; i++)
    {
        T value;
        std::cin >> value;
        tree.Insert(value);
    }
}

template <typename T>
void treeInterface(BinaryTree<T>& tree, const std::string& command)
{
    if (command == "print")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        printTree("", tree.GetRoot(), false);
    }
    else if (command == "insert")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        T value;
        std::cout << "Enter value:" << std::endl;
        std::cin >> value;
        std::cout << "Before insert: " << std::endl;
        printTree("", tree.GetRoot(), false);
        std::cout << "After insert: " << std::endl;
        tree.Insert(value);
        printTree("", tree.GetRoot(), false);
    }
    else if (command == "delete")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        T value;
        std::cout << "Enter value:" << std::endl;
        std::cin >> value;
        if (tree.Find(value) == nullptr)
        {
            std::cout << "Value is not in tree" << std::endl;
        }
        else
        {
            std::cout << "Before delete: " << std::endl;
            printTree("", tree.GetRoot(), false);
            tree.DeleteElement(value);
            std::cout << "After delete: " << std::endl;
            printTree("", tree.GetRoot(), false);
        }
    }
    else if (command == "is_sub_tree")
    {
        std::cout << "Create main tree:" << std::endl;
        setTree(tree);
        std::cout << "Create sub tree:" << std::endl;
        BinaryTree<T> subTree;
        setTree(subTree);
        tree.IsSubTree(subTree) == 1 ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
    }
    else if (command == "get_sub_tree")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Enter value:" << std::endl;
        T value;
        std::cin >> value;
        std::cout << "Main tree: " << std::endl;
        printTree("", tree.GetRoot(), false);
        std::cout << "Sub tree:" << std::endl;
        printTree("", tree.GetSubTree(value).GetRoot(), false);
    }
    else if (command == "find_min")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Min value: " << tree.FindMin()->GetValue() << std::endl;
    }
    else if (command == "find_max")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Max value: " << tree.FindMax()->GetValue() << std::endl;
    }
    else if (command == "balance")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Before balance: " << std::endl;
        printTree("", tree.GetRoot(), false);
        std::cout << "After balance: " << std::endl;
        tree.Balance();
        printTree("", tree.GetRoot(), false);
    }
    else if (command == "KPL")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Result: " << std::endl;
        printKPL(tree.GetRoot());
    }
    else if (command == "LPK")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Result: " << std::endl;
        printLPK(tree.GetRoot());
    }
    else if (command == "PKL")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Result: " << std::endl;
        printPKL(tree.GetRoot());
    }
    else if (command == "PLK")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Result: " << std::endl;
        printPLK(tree.GetRoot());
    }
    else if (command == "LKP")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Result: " << std::endl;
        printLKP(tree.GetRoot());
    }
    else if (command == "KLP")
    {
        std::cout << "Create tree:" << std::endl;
        setTree(tree);
        std::cout << "Result: " << std::endl;
        printKLP(tree.GetRoot());
    }
    else
    {
        throw std::invalid_argument("Unknown command");
    }
}

#endif //LAB4_MEPHI_UI_H