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

void getMoneyFromATM(std::map<int, int> &typeMoneyInATM);

void print(const std::map<int, int> &typeMoneyInATM, const int &sum);

void updateMoneyToATM(const std::map<int, int> &typeMoneyInATM);

int main() {
    std::srand(std::time(nullptr));

    std::map<int, int> typeMoneyInATM{{100,  0},
                                      {200,  0},
                                      {500,  0},
                                      {1000, 0},
                                      {2000, 0},
                                      {5000, 0}};

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

void addMoneyToATM() {
    int typeMoney[]{100, 200, 500, 1000, 2000, 5000};
    std::ofstream file("..\\ATMMachine.bin", std::ios::binary);
    for (int i = 0; i < 1000; ++i) {
        file.write((char *) &typeMoney[std::rand() % 6], sizeof(typeMoney[0]));
    }
    file.close();
}

void getMoneyFromATM(std::map<int, int> &typeMoneyInATM) {
    int moneyToATM = 0;
    std::ifstream inFile("..\\ATMMachine.bin", std::ios::binary);

    while (true) {
        int temp;
        inFile.read((char *) &temp, sizeof(temp));
        if (inFile.eof())
            break;
        moneyToATM += temp;
        ++typeMoneyInATM[temp];
    }
    std::cout << moneyToATM;
    inFile.close();

    std::cout << "Input sum: ";
    int sum = 0;
    std::cin >> sum;

    if (sum > moneyToATM) {
        std::cout << "There is not enough money in the ATM" << std::endl;
    }
    if (sum == moneyToATM) {
        for (auto &[key, value]: typeMoneyInATM) {
            value = 0;

        }
        updateMoneyToATM(typeMoneyInATM);
        print(typeMoneyInATM, sum);

    }
    if (sum < moneyToATM) {
        int temp = sum;
        bool noMoney = false;
        while (temp != 0) {
            if (temp >= 5000) {
                if (typeMoneyInATM.at(5000) > 0) {
                    temp -= 5000;
                    --typeMoneyInATM[5000];
                    continue;
                }
            }
            if (temp >= 2000) {
                if (typeMoneyInATM.at(2000) > 0) {
                    temp -= 2000;
                    --typeMoneyInATM[2000];
                    continue;
                }
            }
            if (temp >= 1000) {
                if (typeMoneyInATM.at(1000) > 0) {
                    temp -= 1000;
                    --typeMoneyInATM[1000];
                    continue;
                }
            }
            if (temp >= 500) {
                if (typeMoneyInATM.at(500) > 0) {
                    temp -= 500;
                    --typeMoneyInATM[500];
                    continue;
                }
            }
            if (temp >= 200) {
                if (typeMoneyInATM.at(200) > 0) {
                    temp -= 200;
                    --typeMoneyInATM[200];
                    continue;
                }
            }
            if (temp >= 100) {
                if (typeMoneyInATM.at(100) > 0) {
                    temp -= 100;
                    --typeMoneyInATM[100];
                    continue;
                }
            }
            noMoney = true;
            break;
        }
        if (noMoney) {
            std::cout << "There is not enough money in the ATM" << std::endl;
        } else {
            updateMoneyToATM(typeMoneyInATM);
            print(typeMoneyInATM, sum);

        }
    }


}

void print(const std::map<int, int> &typeMoneyInATM, const int &sum) {
    std::cout << "The amount of " << sum << " has been issued. The following denominations remained in the ATM:"
              << "\n5000 rub: " << typeMoneyInATM.at(5000) << "\n2000 rub: " << typeMoneyInATM.at(2000)
              << "\n1000 rub: " << typeMoneyInATM.at(1000) << "\n500 rub: " << typeMoneyInATM.at(500)
              << "\n200 rub: " << typeMoneyInATM.at(200) << "\n100 rub: " << typeMoneyInATM.at(100) << std::endl;
}

void updateMoneyToATM(const std::map<int, int> &typeMoneyInATM) {
    std::ofstream file("..\\ATMMachine.bin", std::ios::binary);
    for(const auto& [key, value] : typeMoneyInATM){
        for (int i = 0; i < value; ++i) {
            file.write((char*)&key, sizeof(key));
        }
    }
    file.close();
}
