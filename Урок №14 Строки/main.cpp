#include <iostream>
#include <Windows.h>
#include <string>

bool find_word(std::string sentence, std::string word) {
    for (int i = 0; i < sentence.length(); i++)
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') sentence[i] += 32;
    for (int i = 0; i < word.length(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
    return sentence.find(word) != std::string::npos;
}

int main() {
    SetConsoleCP(65001); SetConsoleOutputCP(65001);
    std::cout << "Введите предложение: ";
    std::string text; std::getline(std::cin, text);

    if (text.empty()) { std::cout << "Строка пуста!"; return 0; }

    for (int i = 0; i < text.length(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            if (text[i] >= 'a' && text[i] <= 'z') text[i] -= 32;
        }
        else {
            if (text[i] >= 'A' && text[i] <= 'Z') text[i] += 32;
        }
    }

    if (text[text.length() - 1] != '.') text += '.';
    std::cout << "Результат: " << text << std::endl;

    std::cout << "Какое слово найти?: ";
    std::string search; std::cin >> search;

    if (find_word(text, search)) std::cout << "Найдено!";
    else std::cout << "Не найдено.";

    return 0;
}
