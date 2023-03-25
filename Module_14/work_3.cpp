/*
Требуется реализовать небольшую программу для сравнения двух двумерных матриц размером 4 × 4 на предмет их полного равенства.
Если матрицы равны друг другу, необходимо взять одну из матриц и привести её к диагональному виду. Программа принимает на вход две целочисленные матрицы A и B,
которые вводятся с помощью std::cin, и сравнивает их на предмет полного равенства. Если матрицы равны, то об этом сообщается в стандартном выводе.
Алгоритм должен быть по возможности оптимальным и не проводить лишних операций. Если матрицы не равны, выводится соответствующее сообщение и выполнение программы прекращается.
Если матрицы равны, то из них выбирается одна и преобразуется в диагональную. Конвертация в диагональную форму делается путём простейшего зануления всех элементов,
лежащих вне главной диагонали. Напомню, что диагональная матрица — это такая матрица, у которой все элементы вне диагонали равны нулю.
Диагональ матрицы, в свою очередь, — это все элементы, расположенные по диагонали от первого элемента первой строки до последнего элемента последней строки.
Итоговую диагональную матрицу можно расположить на месте прежней матрицы, не используя дополнительных переменных.
Результат преобразования требуется вывести в консоль для проверки. Ищите именно оптимальное решение, оно довольно простое.
 */


#include <iostream>

void CreateMatrix(int matrix[4][4]);
bool CompareMatrix(int matrix_1[4][4], int matrix_2[4][4]);
void NewDiagonalMatrix(int matrix[4][4]);
void PrintMatrix(const int matrix[4][4]);


int main() {
    int matrix_1[4][4];
    int matrix_2[4][4];
    CreateMatrix(matrix_1);
    CreateMatrix(matrix_2);

    if (CompareMatrix(matrix_1, matrix_2)) {
        std::cout << "Matrix equal" << std::endl;
        NewDiagonalMatrix(matrix_1);
        PrintMatrix(matrix_1);

    } else {
        std::cout << "Matrix not equal" << std::endl;
    }


}

void CreateMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << "Input num: ";
            std::cin >> matrix[i][j];
        }
    }
}

bool CompareMatrix(int matrix_1[4][4], int matrix_2[4][4]) {
    bool equal = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix_1[i][j] != matrix_2[i][j]) {
                equal = false;
                break;
            }
            if (!equal) {
                break;
            }
        }
    }
    return equal;
}

void NewDiagonalMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                matrix[i][j] = 0;
            }
        }
    }
}

void PrintMatrix(const int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}








