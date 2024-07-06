#ifndef LAB4_MEPHI_MAP_REDUCE_FUNCTIONS_H
#define LAB4_MEPHI_MAP_REDUCE_FUNCTIONS_H

int MapFunc(int i)
{
    return i * i;
}

int ReduceFunc(int a, int b)
{
    return a + b;
}

bool WhereFunc(int a)
{
    return a % 2 == 0;
}

#endif //LAB4_MEPHI_MAP_REDUCE_FUNCTIONS_H