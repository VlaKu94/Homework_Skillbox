/*Требуется реализовать упрощённую симуляцию работы банкомата.
В банкомате могут храниться только бумажные купюры номиналом от 100 до 5000 рублей.
Максимально в банкомате может храниться только 1000 купюр. Все они записываются в отдельный файл.
У банкомата, как у устройства, две основных операции — снятие денег пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”.
Количество купюр рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются случайным образом.

Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем денег.
Пользователь указывает сумму с точностью до 100 рублей. Мы будем считать,
что каждый клиент обладает неограниченным балансом в системе и теоретически может снять любую сумму.
На практике, если данная сумма не может быть снята из-за отсутствия подходящих денег в машине, показывается сообщение, что эта операция невозможна.

После выполнения любой из операций программа завершает выполнение. Состояние банкомата должно храниться в отдельном бинарном файле, автономно.*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <map>

void addMoneyToATM();
void getMoneyFromATM(std::map<int, int>& typeMoneyInATM);

int main() {
    std::srand(std::time(nullptr));

    std::map<int, int> typeMoneyInATM;
    char command;
    std::cout << "Input command '-'  or '+': ";
    std::cin >> command;


    switch (command) {
        case '+':
            addMoneyToATM();
            break;
        case '-':
            getMoneyFromATM(typeMoneyInATM);
            break;
        default:
            std::cout << "Command not found!" << std::endl;
    }

}

void addMoneyToATM(){
    int typeMoney[] {100, 200, 500, 1000, 2000, 5000};
    std::ofstream file("..\\ATMMachine.bin", std::ios::binary);
    for (int i = 0; i < 1000; ++i) {
        file << typeMoney[std::rand() % 6] << std::endl;
    }
    file.close();
}

void getMoneyFromATM(std::map<int, int>& typeMoneyInATM){
    std::ifstream inFile("..\\ATMMachine.bin", std::ios::binary);
    if (!inFile.eof()){
        while(!inFile.eof()){
            int temp;
            inFile.read((char*)&temp, sizeof(temp));
            std::cout << temp << std::endl;
            ++typeMoneyInATM[temp];
        }

    } else {
        std::cout << "ATM machine empty" << std::endl;
    }
    inFile.close();
}
