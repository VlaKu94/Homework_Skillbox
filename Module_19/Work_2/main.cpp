/*
 * Разработайте простейший просмотрщик текстовых файлов. В начале программы пользователь вводит путь к текстовому файлу, который требуется открыть и просмотреть.
 * Внутренности файла необходимо вывести в стандартный вывод. Программа должна работать для любых текстовых файлов в формате TXT,
 * но вы можете создать и свой отдельный файл для теста. Главное, чтобы файл был англоязычным, дабы избежать проблем с кодировками.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    //std::string filePath = "..\\words.txt";


    std::ifstream fs;
    int currentLine = 0;
    int counterLines = 2;
    char exit = 'y';

    std::string filePath;
    std::cout << "Input File Path:";
    std::cin >> filePath;


    fs.open(filePath);

    if (fs.is_open()){
        while(exit == 'y') {
            counterLines += currentLine;
            for (std::string line; std::getline(fs, line);++currentLine) {

                std::cout << line << std::endl;
                if (currentLine == counterLines) break;

            }
            if (fs.eof()){
                std::cout << "File end" << std::endl;
                break;
            } else {
                std::cout << "Continue?(y/n)" << std::endl;
                std::cin >> exit;
                currentLine = 0;
            }
        }

    } else {
        std::cout << "Incorrect file path" << std::endl;
    }

    fs.close();


}
