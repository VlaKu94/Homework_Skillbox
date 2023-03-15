/*
 * Вам дали задание разработать хранилище для целочисленных значений во встраиваемой операционной системе.
 * Такие системы работают в большей части техники, которая нас окружает: автомобилях, стиральных машинах, микроволновках, холодильниках.
 * Только вот незадача: объём памяти этой системы очень небольшой, поэтому в хранилище не может находиться более 20 элементов.
 * В хранилище, являющееся вектором, с клавиатуры приходят целочисленные значения и помещаются в конец.
 * При вводе «−1» с клавиатуры необходимо вывести всё содержимое хранилища (20 или менее элементов).
 * При выводе элементы должны быть в том порядке, в котором они добавлялись.
 * Попробуйте написать максимально оптимизированное решение этой задачи, чтобы совершалось как можно меньше расширений и перемещений элементов внутри вектора.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> db;
    int dbSize = 20;
    int number = 0;

    std::cout << "Input number: ";

    while (std::cin >> number) {

        if (number == -1) {
            for (int i = 0; i < db.size(); ++i) {
                std::cout << db[i] << " ";
            }
            std::cout << std::endl;
        } else {
            if (dbSize == db.size()) {
                db.erase(db.begin());
            }
            db.push_back(number);
        }
        std::cout << "Input number: ";
    }

}


