/*
 На вход программе поступают десять фамилий в формате строк. Это фамилии жильцов квартир с первой по десятую.
 Необходимо прочитать эти фамилии и записать в одномерный массив. Далее пользователь вводит три номера квартир.
 Необходимо вывести в консоль фамилию жильца, проживающего в этой квартире. Если пользователь введёт некорректный номер квартиры,
 необходимо сообщить ему об этом.
 */

#include <iostream>
#include <string>

int main() {
    std::string surnameList[10];
    int number = 0;

    for (int i = 0; i < 10; ++i) {
        std::cin >> surnameList[i];
    }

    for (int i = 0; i < 3; ++i) {
        std::cin >> number;
        if (number >= 1 && number <= 10) {
            std::cout << surnameList[number - 1] << std::endl;
        } else {
            std::cout << "wrong apartment number" << std::endl;
        }
    }
}



