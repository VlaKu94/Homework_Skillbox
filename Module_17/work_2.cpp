/*
 * Написать функцию, которая принимает указатель на тип int, по которому размещены 10 переменных типа int.
 * Функция ничего не возвращает, но по тому же указателю элементы должны лежать в обратном порядке.
 */

#include <iostream>

void reverse(int* ptr);
void swap(int* a, int* b);


int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* ptr = &a[0];
    reverse(ptr);

    for(const int& i:a){
        std::cout << i << " ";
    }

    return 0;
}

void reverse(int* ptr) {
    for (int i = 0; i < 6; ++i) {
        swap(&*(ptr + i), &*(ptr + 9 - i));
    }


}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
