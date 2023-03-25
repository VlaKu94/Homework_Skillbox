/*
После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. Всего в пупырке 12 на 12 шариков-пузырьков.
Состояние любого пузырька: он либо целый, либо нет, то есть true или false (тип массива — bool).
Для начала требуется реализовать отдельную функцию инициализации пупырки начальным состоянием: полностью целая пупырка, все элементы true.

Программа заключается в последовательном лопании целых регионов пузырьков.
Перед каждым таким лопанием надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый.
Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопание. Пользователь вводит две координаты:
начала региона и конца региона. Процедура лопания пузырей должна быть реализована с помощью отдельной функции,
все аргументы должны проверяться на валидность, что они в в рамках диапазона возможных значений, иначе должна быть выведена ошибка.
После лопания каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

Лопание должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает выполнение.
Вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, так как функция выполняется после каждого лопания.
 */


#include <iostream>
#include <vector>

void CreateMatrix(bool matrix[12][12]);
void PrintMatrix(const bool matrix[12][12]);
void DestroyBubble(bool matrix[12][12], int x1, int y1, int x2, int y2, int& count);



int main() {
    bool matrix[12][12];
    int count = 144;

    CreateMatrix(matrix);


    while(count > 0) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;

        PrintMatrix(matrix);

        std::cout << "Input(X1:Y1): ";
        std::cin >> x1 >> y1;
        std::cout << "Input(X2:Y2): ";
        std::cin >> x2 >> y2;
        if (x1 < 0 || x1 > 12 || x2 < 0 || x2 > 12 || y1 < 0 || y1 > 12 || y2 < 0 || y2 > 12){
            std::cout << "Incorrect coordinate. Try again" << std::endl;
            continue;
        }
        DestroyBubble(matrix, x1, y1, x2, y2, count);
    }
    PrintMatrix(matrix);

}

void CreateMatrix(bool matrix[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            matrix[i][j] = true;
        }
    }
}

void PrintMatrix(const bool matrix[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (matrix[i][j]) {
                std::cout << 'O' << " ";
            } else {
                std::cout << 'X' << " ";
            }

        }
        std::cout << std::endl;

    }
}

void DestroyBubble(bool matrix[12][12], int x1, int y1, int x2, int y2, int& count) {
    for (int i = x1; i < x2; ++i) {
        for (int j = y1; j < y2; ++j) {
            if (matrix[i][j]){
                std::cout << "Pop!" << std::endl;
                matrix[i][j] = false;
                --count;
            }
        }
    }
}










