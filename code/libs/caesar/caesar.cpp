#include <iostream>
#include <string>
#include <fstream>
#include "caesar.h"
using namespace std;

string caesarEncrypt(const string& text, int shift) {
    string result = text;
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = static_cast<unsigned char>((static_cast<unsigned char>(result[i]) + shift) % 256);
    }
    return result;
}
string caesarDecrypt(const string& text, int shift) {
    string result = text;
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = static_cast<unsigned char>((static_cast<unsigned char>(result[i]) - shift + 256) % 256);
    }
    return result;
}
void codeCaesar(string& inNameFile, int shift, int choice) {
    string text, NameFile, outNameFile;
    ifstream infile(inNameFile, ios::binary);
    if (!infile) {
        cerr << "Ошибка: не удалось открыть файл: " << inNameFile << endl;
        return;
    }
    char byte;
    while (infile.get(byte)) text += byte;
    infile.close();
    if (choice == 1) {
        string encrypted = caesarEncrypt(text, shift);
        cout << "Название файла для зашифрованных данных (пример: Encrypted.bin): ";
        cin >> NameFile;
        ofstream outfile(NameFile, ios::binary);
        if (!outfile) {
            cerr << "Ошибка: не удалось создать файл: " << NameFile << endl;
            return;
        }
        outfile.write(encrypted.c_str(), encrypted.size());
        outfile.close();
        cout << "Успешно создан зашифрованный файл: " << NameFile << endl;
        
    } else if (choice == 2) {
        string decrypted = caesarDecrypt(text, shift);
        cout << "Название файла для расшифрованных данных (пример: Decrypted.bin): ";
        cin >> outNameFile;
        ofstream outfile(outNameFile, ios::binary);
        if (!outfile) {
            cerr << "Ошибка: не удалось создать файл: " << outNameFile << endl;
            return;
        }
        outfile.write(decrypted.c_str(), decrypted.size());
        outfile.close();
        cout << "Успешно создан расшифрованный файл: " << outNameFile << endl;
    } else {
        cout << "Неверный выбор." << endl;
    }
}