/*
Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.
Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @.
 Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов.
 Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним символом,
 а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:

!#$%&'*+-/=?^_`{|}~

Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.
 */


#include <iostream>
#include <string>
#include <algorithm>

bool checkPart(const std::string &Part, const std::string &symbolDictionary, const int &partLength);


int main() {
    std::string adress;
    bool correctAdress = true;
    std::string correctSymbol = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.-1234567890";
    std::string additionalCorrectSymbol = "!#$%&'*+/=?^_`{|}~";

    //Корректные адреса:
    //adress = "simple@example.com";
    //adress = "very.common@example.com";
    //adress = "disposable.style.email.with+symbol@example.com";
    //adress = "other.email-with-hyphen@example.com";
    //adress = "fully-qualified-domain@example.com";
    //adress = "user.name+tag+sorting@example.com";
    //adress = "x@example.com";
    //adress = "example-indeed@strange-example.com";
    //adress = "admin@mailserver1";
    //adress = "example@s.example";
    //adress = "mailhost!username@example.org";
    //adress = "user%example.com@example.org";

    //Некорректные адреса:
    //adress = "John..Doe@example.com";
    //adress = "Abc.example.com";
    //adress = "A@b@c@example.com";
    //adress = "ab(c)d,e:f;g<h>i[j\k]l@example.com";
    //adress = "1234567890123456789012345678901234567890123456789012345678901234+x@example.com";
    adress = "i_like_underscore@but_its_not_allow_in _this_part.example.com";

    // получаем количество символов '@' в строке
    int counter = std::count(adress.begin(), adress.end(), '@');

    // проверяем, что первый и последний символ не точка, количество символов '@'и длину строки
    if (adress[0] != '.' && adress[adress.length() - 1] != '.' && counter == 1 &&
          adress.length() >= 3 && adress.length() <= 128){

        std::string leftPart;
        leftPart += adress[0];
        int leftPartLength = 63;
        std::string rightPart;
        int rightPartLength = 64;
        bool bound = false;

        for (int i = 1; i < adress.length(); ++i) {
            // проверяем, что две точки не идут друг за другом
            if (adress[i] == '.' && adress[i - 1] == '.'){
                correctAdress = false;
                break;
            }

            // отмечает границу между левой и правой частью
            if (adress[i] == '@'){
                // проверяем, корректная левая часть или нет
                if (!checkPart(leftPart, correctSymbol + additionalCorrectSymbol, leftPartLength)){
                    correctAdress = false;
                    break;
                }
                bound = true;
                continue;
            }

            if (bound){
                rightPart += adress[i];
            } else {
                leftPart += adress[i];
            }
        }
        correctAdress = checkPart(rightPart, correctSymbol, rightPartLength);
    } else{
        correctAdress = false;
    }

    std::cout << (correctAdress ? "Yes" : "No") << std::endl;
}

bool checkPart(const std::string &part, const std::string &symbolDictionary, const int &partLength) {
    if (part.length() < 1 || part.length() > partLength) return false;
    for (int i = 0; i < part.length(); ++i) {
        if (std::count(symbolDictionary.begin(), symbolDictionary.end(), part[i]) == 0) return false;
    }
    return true;
}

