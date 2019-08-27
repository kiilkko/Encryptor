// Encryptor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "MonoAlphabeticAlgorithm.h"
#include "PermutationAlgorithm.h"

using namespace std;
    

int main ()
    {
        SetConsoleCP (1251);
        SetConsoleOutputCP (1251);
        setlocale (LC_ALL, "RUS");

        string anOrigin;
        locale loc1;
        std::cout << "Введите текст (одной строкой): ";
        std::getline (std::cin, anOrigin);
       
        string aKey;
        std::cout << "Введите ключ (одной строкой): ";
        std::getline (std::cin, aKey);

        if (aKey.size()>=anOrigin.size()) {
            std::cout << "Ключ должен быть меньше текста!";
        } else {
            int aChoice;
            std::cout << "Выберите, что нужно сделать с текстом:" << endl;
            std::cout << "1 - Зашифровать (шифр моноалфавитной замены)" << endl;
            std::cout << "2 - Зашифровать (шифр перестановки)" << endl;
            std::cout << "3 - Расшифровать (шифр моноалфавитной замены)" << endl;
            std::cout << "4 - Расшифровать (шифр перестановки)" << endl;
            std::cin >> aChoice;
            if (aChoice == 1) {
                MonoAlphabeticAlgorithm anEngine (aKey, anOrigin);
                auto aResult = anEngine.Encrypt();
                for (const auto& e : aResult) {
                    std::cout << e + " ";
                }
            } else if (aChoice == 2) {
                PermutationAlgorithm anEngine (aKey, anOrigin);
                auto aResult = anEngine.Encrypt();
                for (const auto& e : aResult) {
                    std::cout << e + " ";
                }
            } else if (aChoice == 3) {
                MonoAlphabeticAlgorithm anEngine (aKey, anOrigin);
                auto aResult = anEngine.Decrypt();
                std::cout << aResult << endl;
            } else if (aChoice == 4) {
                PermutationAlgorithm anEngine (aKey, anOrigin);
                auto aResult = anEngine.Decrypt();
                std::cout << aResult << endl;
            } else {
                std::cout << "Данное значение не предусмотрено. Выберите 1, 2, 3 или 4." << endl;
            }
        }

        system ("pause");
    }
