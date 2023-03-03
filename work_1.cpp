#include <iostream>
#include <string>

std::string encryptCaesar(const std::string &str, const int &number);
std::string decryptCaesar(const std::string &str, const int &number);

int main() {

    /*
    std::string str("Lorem ipsum dolor sit amet consectetur adipiscing elit sed do "
                    "eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim "
                    "veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat "
                    "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
                    "pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum");
    */

    std::string str("The quick brown fox jumps over the lazy dog");
    int offset;
    std::cout << "Input number:";
    std::cin >> offset;
    std::cout << encryptCaesar(str, offset) << std::endl;
    std::cout << decryptCaesar(encryptCaesar(str, offset), offset) << std::endl;

}

std::string encryptCaesar(const std::string &str, const int &number){
    std::string newStr = "";


    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' '){
            newStr += ' ';
            continue;
        }
        if (number > 0){
            if (str[i] >= 'a' && str[i] <= 'z'){
                newStr += ((str[i] - 'a' + number) % 26) + 'a';
            } else if (str[i] >= 'A' && str[i] <= 'Z'){
                newStr += ((str[i] - 'A' + number) % 26) + 'A';
            }
        } else {
            if (str[i] >= 'a' && str[i] <= 'z'){
                newStr += ((str[i] - 'z' + number) % 26) + 'z';
            } else if (str[i] >= 'A' && str[i] <= 'Z'){
                newStr += ((str[i] - 'Z' + number) % 26) + 'Z';
            }
        }

    }

    return newStr;
}

std::string decryptCaesar(const std::string &str, const int &number){

    return encryptCaesar(str, -number);
}
