/*
 * Создайте в своей программе функцию float travelTime(float distance, float speed).
 * Она будет находить время в пути и при этом использовать assert, чтобы отбросить нулевую и отрицательную скорость.
 * Вызовите эту функцию в main. Убедитесь, что падение происходит за счёт assert. Не забудьте подключить заголовочный файл cassert.
*/

#include <iostream>
#include <cassert>

float travelTime(float distance, float speed);

int main() {
    float distance = 0;
    float speed;
    float time = 0;

    std::cout << "Input distance and speed: " << std::endl;
    std::cin >> distance >> speed;

    time = travelTime(distance, speed);
    std::cout << "Travel time: " << time << std::endl;

}

float travelTime(float distance, float speed) {
    assert(speed > 0);
    return distance / speed;
}

