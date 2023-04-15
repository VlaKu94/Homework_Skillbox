/*
Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на 1, 2 или 3 ступеньки вверх.
Кролик хочет допрыгать до n-й ступеньки, но может сделать это большим количеством способов.

Напишите рекурсивную функцию, которая принимает число n типа int, а возвращает количество способов, которыми кролик может доскакать до n-й ступеньки.
 */


#include <iostream>

int jump(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return jump(n - 1) + jump(n - 2) + jump(n - 3);
}

int main() {
    std::cout << jump(4);

}