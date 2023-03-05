/*
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно.
Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, быть не должно.

Пользователь вводит строку, задающую IP-адрес через стандартный ввод.
В результате программа должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так.
 */

#include <iostream>
#include <string>

bool checkPart(const std::string &part);

int main() {
    std::string ipAdress;
    bool correctIp = true;

    //Корректные:
    ipAdress = "127.0.0.1";
    //ipAdress = "255.255.255.255";
    //ipAdress = "1.2.3.4";
    //ipAdress = "55.77.213.101";

    //Некорректные:
    //ipAdress = "255.256.257.258";
    //ipAdress = "0.55.33.22.";
    //ipAdress = "10.00.000.0";
    //ipAdress = "23.055.255.033";
    //ipAdress = "65.123..9";
    //ipAdress = "a.b.c.d";

    // проверяем, что первый и последний символ не точка
    if (ipAdress[0] != '.' && ipAdress[ipAdress.length() - 1] != '.'){
        bool bound = false;
        std::string part;

        for (int i = 0; i < ipAdress.length(); ++i) {
            // проверяем, что не идут две точки подряд и в строке только цифры или точка
            if (!(ipAdress[i] >= '0' && ipAdress[i] <= '9' || ipAdress[i] == '.') ||
                  !(i == ipAdress.length()) && ipAdress[i] == '.' && ipAdress[i + 1] == '.'){

                correctIp = false;
                break;
            }

            // отделяем часть между точками, иначе добавдяем цифру к октету
            if (ipAdress[i] == '.') {
                bound = true;
            } else {
                part += ipAdress[i];
            }

            // проверяем на корректность часть ip
            if (bound){
                if (!checkPart(part)) {
                    correctIp = false;
                    break;
                }
                bound = false;
                part = "";
            }
        }

    } else {
        correctIp = false;
    }

    std::cout << (correctIp ? "Valid" : "Invalid") << std::endl;
}

bool checkPart(const std::string &part) {
    int number = std::stoi(part);

    // проверяем, что число не превышает 255
    if (!(number >= 0 && number <= 255)) return false;

    // проверяем, что нет ведущего нуля и нет лишних нулей
    if ((part.length() == 2 && number < 10 || part.length() == 3 && number < 100)) return false;

    return true;

}

