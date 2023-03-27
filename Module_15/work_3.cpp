/*
С клавиатуры вводятся числа. Когда пользователь вводит «-1»,
необходимо выводить на экран пятое по возрастанию число среди введённых.
Когда пользователь вводит «-2», программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы
 */


#include <iostream>
#include <vector>


int main() {
    int n = 0;
    std::vector<int> vec;
    while(true){
        std::cout << "Input number: ";
        std::cin >> n;

        if (n == -1) {
            if (vec.size() >= 5){
                std::cout << vec[4] << std::endl;
            } else {
                std::cerr << "Less 5 numbers.Try again" << std::endl;
            }
        } else if (n == -2) {
            std::cout << "End program" << std::endl;
            break;
        } else {
            vec.push_back(n);
            for (int i = 0; i < vec.size() - 1; ++i) {
                if (vec[vec.size() - 1] < vec[i]) {
                    int temp = vec[i];
                    vec[i] = vec.back();
                    vec.back() = temp;
                }

            }
            for (int i = 0; i < vec.size(); ++i) {
                std::cout << vec[i] << std::endl;
            }
        }

    }

}












