#include <iostream>
#include <string>
#include <fstream>
#include "atbash.h"
using namespace std;

string atbashAll(const string& data) {
    string result;
    for (unsigned char byte : data) {
        result += static_cast<char>(255 - byte);
    }
    return result;
}
void atbashAsciiFunct(string& inNameFile, int choice) {
    string data, NameFile, outNameFile;
    
    ifstream infile(inNameFile, ios::binary);
    if (!infile) {
        cerr << "Ошибка: не удалось открыть файл: " << inNameFile << endl;
        return;
    }
    char byte;
    while (infile.get(byte)) data += byte;
    infile.close();
    string result = atbashAll(data);
    
    if (choice == 1) {
        cout << "Введите название файла для зашифрованных данных: ";
        cin >> NameFile;
        
        ofstream outfile(NameFile, ios::binary);
        if (!outfile) {
            cerr << "Ошибка: не удалось создать файл: " << NameFile << endl;
            return;
        }
        outfile.write(result.c_str(), result.size());
        outfile.close();
        cout << "Успешно создан зашифрованный файл: " << NameFile << endl;
    } else if (choice == 2) {
        cout << "Введите название файла для расшифрованных данных: ";
        cin >> outNameFile;
        ofstream outfile(outNameFile, ios::binary);
        if (!outfile) {
            cerr << "Ошибка: не удалось создать файл: " << outNameFile << endl;
            return;
        }
        outfile.write(result.c_str(), result.size());
        outfile.close();
        cout << "Успешно создан расшифрованный файл: " << outNameFile << endl;
    } else {
        cout << "Ошибка: некорректный выбор режима." << endl;
    }
}