/*
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат.
Теперь требуется создать простую программу записи в эту ведомость.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ.
Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод строки.

При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл в текстовом режиме.
Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream file("..\\file.txt", std::ios::app);

    std::cout << "Input name and surname: ";
    std::string nameAndSurname;
    std::getline(std::cin, nameAndSurname);


    bool correctDate = true;
    std::string date;

    do{
        correctDate = true;
        std::cout << "Input date in format dd.mm.yyyy: ";
        std::cin >> date;
        if (std::stoi(date.substr(0, 2)) <= 0 || std::stoi(date.substr(0, 2)) > 31) {
            std::cout << "Incorrect day" << std::endl;
            correctDate = false;
        }
        if (std::stoi(date.substr(3, 2)) <= 0 || std::stoi(date.substr(3, 2)) > 12) {
            std::cout << "Incorrect month" << std::endl;
            correctDate = false;
        }
        if (std::stoi(date.substr(6, 4)) < 2023 || std::stoi(date.substr(6, 4)) > 2023) {
            std::cout << "Incorrect year" << std::endl;
            correctDate = false;
        }

    } while(!correctDate);



    std::cout << "Input salary: ";
    int salary;
    std::cin >> salary;

    file << nameAndSurname << " " << date << " " << salary << std::endl;
    file.close();


}
