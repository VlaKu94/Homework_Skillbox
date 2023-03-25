/*
Реализуйте частный случай умножения матрицы на матрицу, а именно умножение вектора на матрицу.
Эта операция распространена в компьютерной индустрии в целом и в компьютерной графике в частности, поэтому это будет хорошим упражнением.

Итак, у нас есть четырёхкомпонентный вектор b, представленный с помощью массива, и матрица a размером 4 × 4,
представленная в виде двумерного массива. Их произведением будет новый четырёхэлементный вектор c.
Его компоненты будут суммой произведений элемента вектора b на строку матрицы a. Индекс столбца при этом равен индексу соответствующей компоненты вектора b,
который мы и рассчитываем.

Все входные данные, матрица a и вектор b вносятся из пользовательского ввода.
Итоговый вектор c надо вывести в консоль (std::cout). Тип данных элементов — всегда float.
Желательно реализовать этот алгоритм с помощью вложенного цикла на умножение колонки.
 */


#include <iostream>
#include <vector>

void CreateMatrix(float matrix[4][4]);
void PrintVector(const float new_vector[]);
void Multiply(const float matrix[4][4], const float old_vector[], float new_vector[]);


int main() {
    float matrix[4][4];
    float old_vector[4] = {5, 2, 3, 6};
    float new_vector[4];

    CreateMatrix(matrix);
    Multiply(matrix, old_vector, new_vector);
    PrintVector(new_vector);

}

void CreateMatrix(float matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << "Input num: ";
            std::cin >> matrix[i][j];
        }
    }
}

void PrintVector(const float new_vector[]) {
    for (int i = 0; i < 4; ++i) {
        std::cout << new_vector[i] << " ";
    }
}

void Multiply(const float matrix[4][4], const float old_vector[], float new_vector[]) {
    for (int i = 0; i < 4; ++i) {
        float temp = 0;
        for (int j = 0; j < 4; ++j) {
            temp += matrix[i][j] * old_vector[j];
        }
        new_vector[i] = temp;
    }

}








