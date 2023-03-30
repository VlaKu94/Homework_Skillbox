/*
Старая добрая игра на страницах всех школьных тетрадей.
Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char.
Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ — X или O (буквы латинского алфавита).
Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает.
Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то объявляется ничья.
Для простоты не будем рассматривать диагональные совпадения — только строго вертикальные и строго горизонтальные.

Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону).
Это можно сделать сразу при объявлении либо с помощью вложенного цикла.
На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение, и игрок должен указать координаты клетки повторно.
После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.
 */


#include <iostream>
#include <string>

void ChangePlayer(char& current_player);
void PrintField(const char field[3][3]);
char CheckWin(const char field[3][3]);

int main() {
    char field[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    int n = 0;
    char player_win = '-';
    char current_player = 'X';


    while(n <= 9 && player_win == '-') {
        int x = 0;
        int y = 0;
        std::cout << "Player " << current_player << " Input coordinates(X and Y): ";
        std::cin >> x >> y;
        if (x >= 3 || y >= 3) {
            std::cout << "Incorrect coordinates. Try again" << std::endl;
            continue;
        }
        if (field[x][y] != ' ') {
            std::cout << "This cell is occupied. Try again" << std::endl;
            continue;
        }
        field[x][y] = current_player;
        PrintField(field);
        player_win = CheckWin(field);
        ChangePlayer(current_player);
        ++n;
    }

    if (player_win == '-') {
        std::cout << "Nobody" << std::endl;
    } else if (player_win == 'X') {
        std::cout << "Winner - " << player_win << std::endl;
    } else if (player_win == 'O') {
        std::cout << "Winner - " << player_win << std::endl;
    }

}

void ChangePlayer(char& current_player) {
    if (current_player == 'X')  {
        current_player = 'O';
    } else {
        current_player = 'X';
    }
}

void PrintField(const char field[3][3]) {
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            std::cout << field[row][column];
        }
        std::cout << std::endl;
    }
}

char CheckWin(const char field[3][3]) {
    char win = '-';

    for (int row = 0; row < 3; ++row) {
        // запоминаем первый символ по горизонтали
        char horizontal = field[row][0];
        // запоминаем первый символ по вертикали
        char vertical = field[0][row];
        bool horizontal_check = true;
        bool vertical_check = true;

        for (int column = 0; column < 3; ++column) {
            if (horizontal != field[row][column] && vertical != field[column][row]) {
                horizontal_check = false;
                vertical_check = false;
                break;
            }

            if (horizontal != field[row][column] || horizontal == ' ') horizontal_check = false;
            if (vertical != field[column][row] || vertical == ' ') vertical_check = false;

        }

        if (horizontal_check) win = horizontal;
        if (vertical_check) win = vertical;

        if(win != '-') break;

    }

    return win;
}







