/*
* Напишите небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь,
* составьте новое число с плавающей точкой (типа double) и выведите это число обратно в консоль для проверки.
* Целая часть — это часть числа, которая находится до точки (запятой), дробная — после.
*/

#include <iostream>
#include <string>
#include <cmath>

double StringToDouble(const std::string &left, const std::string &right);

int main() {
    std::string left;
    std::string rigth;

    std::cout << "Input left number: ";
    std::cin >> left;
    std::cout << "Input rigth number: ";
    std::cin >> rigth;
    std::cout << "Fractional number - " << StringToDouble(left, rigth) << std::endl;
}

double StringToDouble(const std::string &left, const std::string &right) {
    return (std::stod(left) + std::stod(right) / std::pow(10, right.size()));
}






