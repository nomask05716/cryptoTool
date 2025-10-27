#include <iostream>
#include <string>
#include <fstream>
#include "atbash.h"
using namespace std;

string atbashUniversal(const string& text) {
    string result;
    
    for (unsigned char c : text) {
        if (c >= 65 && c <= 90) {
            result += static_cast<char>(65 + (90 - c));
        }
        else if (c >= 97 && c <= 122) {
            result += static_cast<char>(97 + (122 - c));
        }
        else if (c >= 192 && c <= 223) {
            result += static_cast<char>(192 + (223 - c));
        }
        else if (c >= 224 && c <= 255) {
            result += static_cast<char>(224 + (255 - c));
        }
        else if (c >= 48 && c <= 57) {
            result += static_cast<char>(48 + (57 - c));
        }
        else {
            result += c;
        }
    }
    return result;
}
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