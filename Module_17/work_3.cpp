/*
Написать функцию, которая принимаем указатель на char, по которому лежит строка.
Функция должна возвращать true, если вторая строка является подстрокой первой.
 */

#include <iostream>
#include "cstring"

bool substr(char* a, char* b);


int main()
{
    char* a = "Hello world";

    char* b = "wor";

    char* c = "banana";

    std::cout << substr(a,b) << " " << substr(a,c);
}

bool substr(char* a, char* b){
    for (int i = 0; i <= strlen(a) - strlen(b) ; ++i) {
        bool result = true;
        for (int j = 0; j < strlen(b); ++j) {
            if (a[i + j] != b[j]){
                result = false;
                break;
            }
        }
        if (result)
            return result;

        result = true;
    }
    return false;
}
