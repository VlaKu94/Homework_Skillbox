/*
 * В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет.
 * Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане.
 * Исходя из этого офсета вычисляется новый активный сектор, который и будет играть в этом ходе.
 * Если выпавший сектор уже играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.
 *
 * Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора. Вопрос показывается на экране.
 *
 * После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом, который хранится во втором файле, ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.
 *
 * Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.
 *
 * Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель и программа заканчивает работу.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFile(std::vector<std::string>& vec, std::ifstream& fs);
void calculateSector(int& currentSector, int offset, std::vector<bool>& sectors);

int main() {
    std::string questionsPath = "..\\questions.txt";
    std::string answerPath = "..\\answers.txt";

    std::vector<bool> sectors(13, false);
    int playerScore = 0;
    int viewersScore = 0;

    std::ifstream questionsStream;
    std::ifstream answerStream;

    questionsStream.open(questionsPath);
    answerStream.open(answerPath);



    if (questionsStream.is_open() && answerStream.is_open()){
        std::vector<std::string> questions;
        std::vector<std::string> answers;
        int currentSector = 0;

        readFile(questions, questionsStream);
        readFile(answers, answerStream);

        while(playerScore < 6 && viewersScore < 6){
            int offset = 0;
            std::string playerAnswer;

            std::cout << "Enter a number (1, 13) to select a sector: ";
            std::cin >> offset;

            calculateSector(currentSector, offset, sectors);

            std::cin.get();
            std::cout << "Answer the question - " << questions[currentSector - 1] << ": ";
            std::getline(std::cin,playerAnswer);

            if (playerAnswer == answers[currentSector - 1]) {
                ++playerScore;
            } else {
                ++viewersScore;
            }
        }
        if (playerScore == 6) {
            std::cout << "Winner - player" << std::endl;
        } else {
            std::cout << "Winner - viewers" << std::endl;
        }

    } else {
        std::cout << "Incorrect file path" << std::endl;
    }

    questionsStream.close();
    answerStream.close();

}

void readFile(std::vector<std::string>& vec, std::ifstream& fs){
    for (std::string line; std::getline(fs, line); ) {
        vec.push_back(line);
    }
}

void calculateSector(int& currentSector, int offset, std::vector<bool>& sectors){
    do {
        if ((offset + currentSector) <= 13) {
            currentSector += offset;
        } else {
            currentSector += offset - 13;
        }
        offset = 1;
    } while(sectors[currentSector - 1]);
    sectors[currentSector - 1] = true;

}
