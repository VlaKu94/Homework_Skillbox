/*
 * Разработайте простейший просмотрщик текстовых файлов. В начале программы пользователь вводит путь к текстовому файлу, который требуется открыть и просмотреть.
 * Внутренности файла необходимо вывести в стандартный вывод. Программа должна работать для любых текстовых файлов в формате TXT,
 * но вы можете создать и свой отдельный файл для теста. Главное, чтобы файл был англоязычным, дабы избежать проблем с кодировками.
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath = "..\\document.txt";
    std::ifstream fs;
    int maxSalary = 0;
    int sumSalary = 0;
    std::string nameEmployee;


    fs.open(filePath);

    if (fs.is_open()){
        while(!fs.eof()){
            std::string name, surname, date;
            int salary = 0;
            fs >> name >> surname >> salary >> date;
            sumSalary += salary;
            if (salary > maxSalary) {
                maxSalary = salary;
                nameEmployee = name + " " + surname;
            }
        }

        std::cout << "Max Salary - " << nameEmployee << std::endl;
        std::cout << "Sum Salary - " << sumSalary << std::endl;

    } else {
        std::cout << "Incorrect file path" << std::endl;
    }

    fs.close();


}
