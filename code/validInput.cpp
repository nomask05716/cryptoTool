#include <iostream>
#include "validInput.h"
#include <limits>
using namespace std;
int ValidInputMainMenu()
{
    while (true)
    {
        try
        {
            cout << "Введите номер действия: \n1 - Процесс шифрования/дешифрования текста. \n2 - Процесс шифрования/дешифрования файла. \nВаш выбор >>";
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
int ValidInputSubMenu()
{
    while (true)
    {
        try
        {
            cout << "Введите номер алгоритма: \n1 - Шифр Цезаря. \n2 - Табличная кодировка. \n3 - Шифр Атбаша \nВаш выбор >>";
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
    int input;
    while (true) {
        cout << "Введите ключ >> ";
        cin >> input;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cerr << "Ошибка: введено не число. Попробуйте ещё раз." << endl;
        } else {
            return input; 
        }
    }
}
int ValidInputAction() {
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
        }
        return input;
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
            if (input.empty()){
                throw runtime_error("Ошибка. Путь не может быть пустым");
            }
            return input;
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
}