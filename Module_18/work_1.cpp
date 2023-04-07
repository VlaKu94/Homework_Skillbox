/*
Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int (одного размера) и обменивающую значения этих массивов.
 */


#include <iostream>
#include <vector>

void swapvec(std::vector<int>& v, int* arr);

int main() {
    std::vector<int> v = {1,2,3,4};
    int a[] = {2,4,6,8};

    swapvec(v,a);

    for(const auto& i : v) {
        std::cout << i;
    }
    
    std::cout << std::endl;

    for(const auto& i : a) {
        std::cout << i;
    }
    
}

void swapvec(std::vector<int>& v, int* arr) {
    for (int i = 0; i < v.size(); ++i) {
        int temp = v[i];
        v[i] = arr[i];
        arr[i] = temp;
    }
    
}















