#include <iostream>
#include "validInput.h"
#include <limits>
#include <filesystem>
#include "../../include/cryptoLibs.h"
using namespace std;

int validInputMainMenu()
{
    while (true)
    {
        try
        {
            cout << "Выберите формат работы программы: \n1 - Процесс шифрования/дешифрования в консоли \n2 - Процесс шифрования/дешифрования файла \nВаш выбор >>";
            string input;
            getline(cin, input);
            size_t pos = 0;
            int numTask = stoi(input, &pos);
            if (pos != input.length())
            {
                throw runtime_error("Ошибка: введите целое число без лишних символов.");
            }
            if (numTask < 1)
                throw runtime_error("Ошибка: Номер действия начинается с 1.");
            if (numTask > 2)
                throw runtime_error("Ошибка: Всего 2 действия.");

            return numTask; 
        }
        catch (const invalid_argument &)
        {
            cout << "Ошибка: введено не число. Попробуйте ещё раз." << endl;
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
}
int validInputSubMenu()
{
    while (true)
    {
        try
        {
            cout << "Введите номер алгоритма: \n1 - Шифр Цезаря \n2 - Табличная шифровка \n3 - Шифр Атбаша \nВаш выбор >>";
            string input;
            getline(cin, input);
            size_t pos = 0;
            int numAlgo = stoi(input, &pos);
            if (pos != input.length())
            {
                throw runtime_error("Ошибка: введите целое число без лишних символов.");
            }
            if (numAlgo < 1)
                throw runtime_error("Ошибка: Номер алгоритма начинается с 1.");
            if (numAlgo > 3)
                throw runtime_error("Ошибка: Всего 3 алгоритма.");

            return numAlgo; 
        }
        catch (const invalid_argument &)
        {
            cout << "Ошибка: введено не число. Попробуйте ещё раз." << endl;
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
}
int validInputKeyCaesar() {
    while (true)
    {
        try
        {
            cout << "Введите ключ >>";
            string input;
            getline(cin, input);
            size_t pos = 0;
            int key = stoi(input, &pos);
            if (pos != input.length())
            {
                throw runtime_error("Ошибка: введите целое число без лишних символов.");
            }
            return key; 
        }
        catch (const invalid_argument &)
        {
            cout << "Ошибка: введено не число. Попробуйте ещё раз." << endl;
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
}
int validInputAction() {
    int action;
    string input;
    while (true) {
        cout << "Введите номер действия: \n1 - Процесс шифрования\n2 - Процесс дешифрования.\nВаш выбор >>";
        getline(cin, input);
        if (input == "1" || input == "2") {
            action = stoi(input);
            return action;
        } else {
            cout << "Ошибка: Всего 2 действия.\n";
        }
    }
}

string validInputKey() {
    string input;
    while (true) {
        cout << "Введите ключ >> ";
        getline(cin, input);
        if (input.empty()) {
            cerr << "Ошибка: ключ не может быть пустым. Попробуйте снова." << endl;
        }else{
            return input;
        }
    }
    
}
string validInputPathFile()
{
    while (true)
    {
        try
        {
            cout << "Введите полный путь до файла(если в одной директории,то достаточно названия файла) >>";
            string input;
            getline(cin, input);
            for (auto symbol : input){
                if (symbol == '/'){
                    throw runtime_error("Ошибка. В пути не должно содержаться '/'");
                }
                
            }
            if (!(filesystem::exists(input))){
                cerr << "Ошибка.Отсутствует файл по указанному пути" <<endl;
            }else {
                return input;
            }
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
}