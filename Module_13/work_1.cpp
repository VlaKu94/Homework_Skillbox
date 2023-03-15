/*
 * Необходимо из заданного пользователем вектора удалить число X.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int vectorSize = 0;
    int x = 0;

    std::cout << "Input vector size: ";
    std::cin >> vectorSize;

    for (int i = 0; i < vectorSize; ++i) {
        int temp;
        std::cout << "Input number: ";
        std::cin >> temp;
        vec.push_back(temp);
    }

    std::cout << "Input number to delete: ";
    std::cin >> x;

    for (int i = 0; i < vectorSize; ++i) {
        if (vec[i] == x) {
            vec[i] = vec.back();
            vec.back() = x;
            vec.pop_back();
            --vectorSize;
        }
    }

    for (int i = 0; i < vectorSize; ++i) {
        std::cout << vec[i] << " ";
    }

}



