/*
 * В программе инициализирован массив из 15 целых положительных чисел.
 * Эти числа являются множеством из 14 последовательных чисел, начиная с Х (Х может быть любым), а одно число из ряда повторяется.
 * Необходимо найти повторяющееся число и вывести его в консоль. По возможности используйте минимум дополнительной памяти и проходов по массиву.
*/

#include <iostream>
#include <cassert>

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    //int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 119, 110, 109, 112, 113, 116, 117, 118};
    //int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 106, 110, 109, 112, 113, 116, 117, 118};
    int x = 0;
    std::cout << "Input X: " << std::endl;
    std::cin >> x;

    int arrSum = 0;
    int correctSum = 0;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i) {
        arrSum += numbers[i];
        correctSum += (numbers[x] + i);
    }
    if ( arrSum < correctSum) {
        std::cout << (numbers[x] + 14) - (correctSum - arrSum + numbers[x]) + numbers[x] << std::endl;
    } else {
        std::cout << "Duplicate none" << std::endl;
    }

}



