#ifndef LAB4_MEPHI_TRAVERSE_H
#define LAB4_MEPHI_TRAVERSE_H

#include "Tree.h"

template <typename T>
void printKLP(Node<T> *node)
{
    if (node != nullptr)
    {
        std::cout << "(" << node->GetValue() << ") ";
        printKLP(node->GetLeft());
        printKLP(node->GetRight());
    }
}

template <typename T>
void printKPL(Node<T> *node)
{
    if (node != nullptr)
    {
        std::cout << "(" << node->GetValue() << ") ";
        printPKL(node->GetRight());
        printPKL(node->GetLeft());
    }
}

template <typename T>
void printLPK(Node<T> *node)
{
    if (node != nullptr)
    {
        printLPK(node->GetLeft());
        printLPK(node->GetRight());
        std::cout << "(" << node->GetValue() << ") ";
    }
}

template <typename T>
void printPLK(Node<T> *node)
{
    if (node != nullptr)
    {
        printPLK(node->GetRight());
        printPLK(node->GetLeft());
        std::cout << "(" << node->GetValue() << ") ";
    }
}

template <typename T>
void printLKP(Node<T> *node)
{
    if (node != nullptr)
    {
        printLKP(node->GetLeft());
        std::cout << "(" << node->GetValue() << ") ";
        printLKP(node->GetRight());
    }
}

template <typename T>
void printPKL(Node<T> *node)
{
    if (node != nullptr)
    {
        printPKL(node->GetRight());
        std::cout << "(" << node->GetValue() << ") ";
        printPKL(node->GetLeft());
    }
}

#endif //LAB4_MEPHI_TRAVERSE_H