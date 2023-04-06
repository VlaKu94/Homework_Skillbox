/*
 * Написать функцию, принимающую два указателя на int и меняет местами содержимое данных указателей.
 */

#include <iostream>

void swap(int* a, int* b);

using namespace std;

int main()
{
    int a = 5;
    int b = 3;
    cout << a << "," << b << " - ";
    swap(&a, &b);
    cout << a << "," << b << endl;
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
