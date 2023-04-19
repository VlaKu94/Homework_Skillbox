/*
 * Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу.
 * На выходе программа должна определить, является ли данный файл PNG-изображением.
 * Данная процедура не просто должна смотреть на расширение файла, но и произвести минимальный анализ его внутренностей, в бинарном режиме.
 * Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. Нас будут интересовать первые четыре байта.
 * Первый байт всегда имеет значение −119 (число со знаком минус), а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные друг за другом.
 * Обратите внимание, что все они в верхнем регистре.
 * По результатам проверки пути и внутренностей требуется сообщить пользователю о результате проверки в стандартный вывод.
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    //std::string filePath = "..\\document.txt";
    std::string filePath = "..\\pngwing.png";
    std::ifstream fs;

    char buffer[4];

    bool expansionPNG = filePath.substr(filePath.length() - 3) == "png";

    if (expansionPNG) {
        fs.open(filePath, std::ios::binary);

        if (fs.is_open()){
            fs.read(buffer, sizeof(buffer));
            if ((int)buffer[0] == -119 && buffer[1] == 'P' && buffer[2]  == 'N' && buffer[3] == 'G'){
                std::cout << "File PNG" << std::endl;
            } else {
                std::cout << "File not PNG" << std::endl;
            }
        } else {
            std::cout << "Incorrect file path" << std::endl;
        }

        fs.close();
    } else {
        std::cout << "File not PNG" << std::endl;
    }




}
