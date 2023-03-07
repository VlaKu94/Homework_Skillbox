/*
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 × 3, которая осталась после их поединка.
Вы хотите понять, выиграл ли кто-то из них или они не доиграли.

На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля.
Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная английская буква O), пустая клетка — точкой.

Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.

Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — Vanya won,
иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.
 */


#include <iostream>
#include <string>

bool checkWon(const int& countX, const int& countO, const char& winner);
bool checkNobody(const int& countX, const int& countO, const int &lengthField);

int main() {

//    std::string firstLine = "X..";
//    std::string secondLine = "OXO";
//    std::string thirdLine = "OOO";


//    std::string firstLine = "X..";
//    std::string secondLine = ".X.";
//    std::string thirdLine = "OO.";



//    std::string firstLine = "XXO";
//    std::string secondLine = "OOX";
//    std::string thirdLine = "XOX";


//    std::string firstLine = "XO.";
//    std::string secondLine = "XO.";
//    std::string thirdLine = "X.O";


//    std::string firstLine = "OX.";
//    std::string secondLine = "XOX";
//    std::string thirdLine = "X.O";


//    std::string firstLine = "..X";
//    std::string secondLine = "OX.";
//    std::string thirdLine = "X.O";

    std::string firstLine = "0..";
    std::string secondLine = "...";
    std::string thirdLine = "...";

    bool incorrect = false;
    bool nobody;
    bool won;
    char winner = '-';

    int countX = 0;
    int countO = 0;


    std::string gameField = firstLine + secondLine + thirdLine;
    int lengthLine = firstLine.length();
    int lengthField = gameField.length();


    for (int i = 0; i < lengthField; ++i) {
        // проверяем на допустимые символы
        if (gameField[i] == 'X' || gameField[i] == 'O' || gameField[i] == '.') {

            if (gameField[i] == 'X') countX++; // подсчитываем количество 'X'
            if (gameField[i] == 'O') countO++; // подсчитываем количество 'O'

            // проверяем каждую строку на победителя
            if (i % lengthLine == 0 && i <= lengthField - lengthLine && gameField[i] != '.' && winner == '-'){
                if (gameField[i] == gameField[i + 1] && gameField[i] == gameField[i + 2]){
                    winner = gameField[i];
                }
            }

            // проверяем каждый столбец на победителя
            if (i <= lengthLine - 1 && gameField[i] != '.' && winner == '-') {
                if (gameField[i] == gameField[i + lengthField - lengthLine * 2] && gameField[i] == gameField[i + lengthField - lengthLine * 2]){
                    winner = gameField[i];
                }
            }

            // проверяем диагональ на победителя
            if (i == 0 || i == lengthLine - 1 && gameField[i] != '.' && winner == '-') {
                if (gameField[i] == gameField[lengthField / 2] && gameField[i] == gameField[lengthField - 1 - i]){
                    winner = gameField[i];
                }
            }
        } else {
            incorrect = true;
            break;
        }


    }

    // проверяем, что игрок победил
    won = checkWon(countX, countO, winner);

    // проверяем на ничью
    nobody = checkNobody(countX, countO, lengthField) && !won && !incorrect && winner == '-';

    if (incorrect || !won && !nobody) {
        std::cout << "Incorrect" << std::endl;
    } else {

        if (nobody) {
            std::cout << "Nobody" << std::endl;
        }

        if (winner == 'X' && !nobody) {
            std::cout << "Petya won" << std::endl;
        }

        if (winner == 'O' && !nobody) {
            std::cout << "Vanya won" << std::endl;
        }

    }
}

bool checkWon(const int& countX, const int& countO, const char& winner) {
    if (winner == 'X' && (countX - countO == 1)) return true;
    if (winner == 'O' && (countO - countX == 1)) return true;

    return false;
}

bool checkNobody(const int& countX, const int& countO, const int &lengthField) {
    return (countO + countX <= lengthField) && countO == countX || countX - countO == 1 || countO - countX == 1;
}





