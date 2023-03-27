/*
Вам даётся массив целых чисел и одно число — результат.
Необходимо найти в массиве два числа, сумма которых будет давать результат, и вывести их на экран.
Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.

Пример:

a = {2, 7, 11, 15}. Результат = 9

2 + 7 = 9, так что надо вывести числа 2 и 7
 */


#include <iostream>


int main() {
    int a[] {2, 7, 11, 15};
    int result = 13;

    int first_number = 0;
    int second_number = 0;

    int arr_size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < arr_size; ++i) {
        int temp = result;
        for (int j = i + 1; j < arr_size - 1; ++j) {
            temp -= (a[i] + a[j]);
            if (temp == 0) {
                first_number = a[i];
                second_number = a[j];
                break;
            }
            temp = result;

        }
        if (temp == 0)
            break;
    }

    std::cout << first_number << " " << second_number << std::endl;

}












