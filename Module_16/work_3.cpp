/*
Создайте небольшую программу для вычисления простых действий с числами.
При запуске программа ожидает пользовательского ввода во временную переменную строку.
После ввода строки она распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>” (без пробелов).
Оба числа — это значения с плавающей точкой, повышенной точности (double). Действие может быть одним из: +, −, /, *.
Результат действия выводится в стандартный вывод cout.
*/

#include <iostream>
#include <string>
#include <sstream>

double Division(const double& a, const double& b);

int main() {
    std::string buffer;
    std::cout << "Input dodble1, action, double2: ";
    std::cin >> buffer;
    std::stringstream buffer_stream(buffer);
    double a;
    double b;
    char operation;
    buffer_stream >> a >> operation >> b;

    double result = 0;
    bool incorrect_operation = false;
    double divisior = 1.0;
    switch (operation) {
        case '-':
            result = a - b;
            break;
        case '+':
            result = a + b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = Division(a, b);
            divisior = b;
            break;
        default:
            incorrect_operation = true;
            std::cout << "Incorrect operation" << std::endl;
    }

    if(!incorrect_operation && divisior != 0)
        std::cout << a << " " << operation << " " << b << " = " << result << std::endl;
}

double Division(const double& a, const double& b) {
    if (b != 0) return a / b;

    std::cout << "the divisor cannot be zero" << std::endl;
    return 0;
}








