#ifndef LAB4_MEPHI_TESTS_H
#define LAB4_MEPHI_TESTS_H

#include <cassert>
#include "Complex.h"
#include "MapWhereFunctions.h"

void testTreeConstructors()
{
    const int a[6] = {1, 8, 9, 10, -2, -1};
    BinaryTree<int> test;
    for (int i : a)
    {
        test.Insert(i);
    }

    assert(test.GetRoot()->GetValue() == 1);
    assert(test.GetRoot()->GetRight()->GetValue() == 8);
    assert(test.GetRoot()->GetRight()->GetRight()->GetValue() == 9);
    assert(test.GetRoot()->GetRight()->GetRight()->GetRight()->GetValue() == 10);
    assert(test.GetRoot()->GetLeft()->GetValue() == -2);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetValue() == -1);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetRight() == nullptr);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetLeft()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetRight()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetRight()->GetRight()->GetRight() == nullptr);
}

void testTreeGetters()
{
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c(5, 6);
    Complex d(7, 8);
    Complex e(9, 10);
    Complex f(11, 12);
    BinaryTree<Complex> test;
    test.Insert(a);
    test.Insert(b);
    test.Insert(c);
    test.Insert(d);
    test.Insert(e);
    test.Insert(f);
    assert(test.GetRoot()->GetValue() == a);

    assert(test.GetSubTree(e).GetRoot()->GetValue() == e);
    assert(test.GetSubTree(e).GetRoot()->GetRight()->GetValue() == f);
    assert(test.GetSubTree(e).GetRoot()->GetLeft() == nullptr);
    assert(test.GetSubTree(e).GetRoot()->GetRight()->GetLeft() == nullptr);
    assert(test.GetSubTree(e).GetRoot()->GetRight()->GetRight() == nullptr);
}

void testTreeFind()
{
    int a[6] = {1, 8, 9, 10, -2, -1};
    BinaryTree<int> test;
    for (int i : a)
    {
        test.Insert(i);
    }

    assert(test.Find(1) != nullptr);
    assert(test.Find(8) != nullptr);
    assert(test.Find(9) != nullptr);
    assert(test.Find(10) != nullptr);
    assert(test.Find(-2) != nullptr);
    assert(test.Find(-1) != nullptr);
    assert(test.Find(0) == nullptr);

    assert(test.FindMax()->GetValue() == 10);
    assert(test.FindMin()->GetValue() == -2);
    assert(test.IsElementInTree(10) == true);
    assert(test.IsElementInTree(0) == false);
}

void testTreeDelete()
{
    double a[6] = {1.7, 8.2, 9.5, 10.54, -2.3, -1.6};
    BinaryTree<double> test;
    for (double i : a)
    {
        test.Insert(i);
    }

    test.DeleteElement(8.2);
    assert(test.GetRoot()->GetValue() == 1.7);
    assert(test.GetRoot()->GetRight()->GetValue() == 9.5);
    assert(test.GetRoot()->GetRight()->GetRight()->GetValue() == 10.54);
    assert(test.GetRoot()->GetLeft()->GetValue() == -2.3);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetValue() == -1.6);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetRight() == nullptr);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetLeft()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetRight()->GetLeft() == nullptr);
    assert(test.GetRoot()->GetRight()->GetRight()->GetRight() == nullptr);
}

void testSubTree()
{
    int a[6] = {1, 8, 9, 10, -2, -1};
    BinaryTree<int> test;
    for (int i : a)
    {
        test.Insert(i);
    }

    BinaryTree<int> subTree1 = test.GetSubTree(9);
    BinaryTree<int> subTree2;
    int b[] = {1, 5, 3};
    for (int i : b)
    {
        subTree2.Insert(i);
    }

    assert(test.IsSubTree(subTree1) == true);
    assert(test.IsSubTree(subTree2) == false);
}

void testMap()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[8] = {1, 4, 9, 16, 25, 36, 49, 64};
    BinaryTree<int> test;

    for (int i : a)
    {
        test.Insert(i);
    }

    test.Map(&MapFunc);

    Node<int> *node = test.GetRoot();

    for (int i : b)
    {
        assert(node->GetValue() == i);
        node = node->GetRight();
    }
}

void testWhere()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {2, 4, 6, 8};

    BinaryTree<int> test;
    for (int i : a)
    {
        test.Insert(i);
    }

    test.Where(&WhereFunc);

    for (int i : b)
    {
        assert(test.Find(i) != nullptr);
    }
}

void testBalance()
{
    int a[5] = {5, 1, 10, 20, 35};
    BinaryTree<int> test;
    for (int i : a)
    {
        test.Insert(i);
    }

    test.Balance();

    assert(test.GetRoot()->GetValue() == 20);
    assert(test.GetRoot()->GetLeft()->GetValue() == 5);
    assert(test.GetRoot()->GetRight()->GetValue() == 35);
    assert(test.GetRoot()->GetLeft()->GetLeft()->GetValue() == 1);
    assert(test.GetRoot()->GetLeft()->GetRight()->GetValue() == 10);
}

void testTree()
{
    testTreeConstructors();
    testTreeGetters();
    testTreeFind();
    testTreeDelete();
    testSubTree();
    testMap();
    testWhere();
    testBalance();
}

#endif