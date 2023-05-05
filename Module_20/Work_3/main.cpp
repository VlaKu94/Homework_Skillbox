/*Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt) задаётся список из видов рыб, которые можно в ней поймать. Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.

В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы.
После этого из первого файла друг за другом осуществляется чтение его содержимого, вид за видом.
Если на отдельных шагах вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка) записывается этот вид.

В конце программы показывается, сколько было поймано рыб за текущую ловлю.
Программу можно запускать несколько раз, при этом уже пойманные рыбы должны сохраняться в файле-корзинке.*/

#include <iostream>
#include <fstream>
#include <string>

void addFishToBasket(const std::string& fish);

int main() {
    std::string fish;
    int countFish = 0;
    std::cout << "input fish:";
    std::cin >> fish;

    std::ifstream inFile("..\\river.txt");
    if (inFile.is_open()){
        while(!inFile.eof()){
            std::string tempFish;
            inFile >> tempFish;
            if (tempFish == fish){
                addFishToBasket(fish);
                ++countFish;
            }
        }
    } else{
        std::cout << "File river.txt not found!" << std::endl;
    }

    std::cout << "Count fish - " << countFish << std::endl;
}

void addFishToBasket(const std::string& fish){
    std::ofstream file("..\\basket.txt", std::ios::app);
    file << fish << std::endl;
    file.close();
}