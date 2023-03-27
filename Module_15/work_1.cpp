/*
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве,
что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6.
 */


#include <iostream>


int main() {
    int a[] {-2,1,-3,4,-1,2,1,-5,4};
    int first_index = 0;
    int end_index = 0;
    int max = 0;
    int arr_size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < arr_size; ++i) {
        int temp = 0;
        for (int j = i; j < arr_size; ++j) {
            temp += a[j];
            if (temp > max) {
                max = temp;
                first_index = i;
                end_index = j;
            }
        }
    }

    std::cout << first_index << " " << end_index << std::endl;

}












