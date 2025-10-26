#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "reverse.h"
using namespace std;

string reverseEncrypt(const string& text, const string& key) {
    string result = "";
    int keyLen = key.size();
    
    for (size_t i = 0; i < text.size(); ++i) {
        int shifted = (static_cast<unsigned char>(text[i]) + 
                      static_cast<unsigned char>(key[i % keyLen])) % 256;
        
        string ascii = to_string(shifted);
        reverse(ascii.begin(), ascii.end());
        result += ascii;
        if (i != text.size() - 1) {
            result += " ";
        }
    }
    return result;
}
string reverseDecrypt(const string& text, const string& key) {
    string result = "";
    istringstream iss(text);
    string reverseAscii;
    int keyLen = key.size();
    int index = 0;
    
    while (iss >> reverseAscii) {
        reverse(reverseAscii.begin(), reverseAscii.end());
        int ascii = stoi(reverseAscii);
        ascii = (ascii - static_cast<unsigned char>(key[index % keyLen]) + 256) % 256;
        result += static_cast<unsigned char>(ascii);
        index++;
    }
    return result;
}
void reverseAsciiFunct(string& inNameFile, int choice, string& key) {
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
        string encrypted = reverseEncrypt(text, key);
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
        string decrypted = reverseDecrypt(text, key);
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
        cout << "Некорректный ввод" << endl;
    }
}