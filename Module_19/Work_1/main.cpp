/*
Составьте небольшой текстовый файл «words.txt», в котором последовательно, через пробелы и переносы строк расположены различные слова.
Можете использовать любые англоязычные слова. Разработайте программу, которая искала бы среди этих слов нужное пользователю и
выводила бы общее количество повторений этого слова. 0 — если слово вообще не присутствует в файле.
 */


#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string word = "hello";

    std::ifstream fs;
    fs.open("words.txt");
    int count = 0;
    while(!fs.eof()){
        std::string str;
        fs >> str;
        if(str == word)
            ++count;
    }
    fs.close();

    std::cout << count << std::endl;

}