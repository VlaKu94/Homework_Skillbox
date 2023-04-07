/*
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, а возвращает void.
После завершения работы функции в переменной ans должно оказаться количество чётных цифр в записи числа n.
 */


#include <iostream>

void evendigits(long long i, int& ans) {
    if ((i%10) % 2 == 0 && i > 0) ans += 1;
    if (i > 0) evendigits(i / 10, ans);

}

int main() {
    int ans = 0;

    evendigits(9223372036854775806, ans);
    std::cout << ans;
}