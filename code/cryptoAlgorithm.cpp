#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "cryptoAlgorithm.h"
using namespace std;
void codeCaesar(string& inNameFile,int shift,int choice) {
    string text,NameFile,outNameFile;
    if (choice == 1) {
        ifstream infile(inNameFile,ios::binary);
        if (!infile){
            //cerr << "Файл не может открыться"<<endl;
            return;
        }
        char symbol;
        while (infile.get(symbol)){
            text += symbol;
        }
        infile.close();
        string encrypted = caesarEncrypt(text, shift);
        std::cout << "Название файла. \n Пример: Encrypted.bin"<<endl;
        cin >> NameFile;
        ofstream file(NameFile,ios::binary);
        if (!file){
            cerr << "Файл не может открыться"<<endl;
            return;
        }
        file.write(encrypted.c_str(), encrypted.size());
        file.close();
        std::cout << " Успешно создан файл с зашифрованным текстом:" << NameFile<<endl;
    } else if (choice == 2) {
        ifstream file(inNameFile,ios::binary);
        if (!file){
            cerr << "Не получилось открыть файл,проверьте существует ли этот файл"<<endl;
            return;
        }
        char symbol;
        while(file.get(symbol)){
            text += symbol;
        }
        file.close();
        string decrypted = caesarDecrypt(text, shift);
        std::cout << "Название файла. \n Пример: Decrypted.txt"<<endl;
        cin >> outNameFile;
        ofstream outfile(outNameFile);
        if (!outfile){
            cerr << "Файл не может открыться"<<endl;
        }
        outfile << decrypted;
        outfile.close();
        std::cout << " Успешно создан файл с расшифрованным текстом:" << outNameFile<<endl;
        
    } else {
        std::cout << "Неверный выбор." << endl;
    }
}
void reverseAsciiFunct(string& inNameFile, int choice,string& key) {
    string text, NameFile, outNameFile;
    if (choice == 1) {
        ifstream infile(inNameFile, ios::binary);
        if (!infile) {
            cerr << "Файл не может открыться" << endl;
            return;
        }
        char symbol;
        while (infile.get(symbol)) {
            text += symbol;
        }
        infile.close();


        string encrypted = reverseEncrypt(text, key);

        cout << "Название файла. Пример: Encrypted.bin" << endl;
        cin >> NameFile;

        ofstream file(NameFile, ios::binary);
        if (!file) {
            cerr << "Файл не может открыться" << endl;
            return;
        }
        file.write(encrypted.c_str(), encrypted.size());
        file.close();

        cout << "Успешно создан файл с зашифрованным текстом: " << NameFile << endl;

    } else if (choice == 2) {
        ifstream file(inNameFile, ios::binary);
        if (!file) {
            cerr << "Не получилось открыть файл, проверьте существует ли этот файл" << endl;
            return;
        }
        char symbol;
        while (file.get(symbol)) {
            text += symbol;
        }
        file.close();
        string decrypted = reverseDecrypt(text, key);

        cout << "Название файла. Пример: Decrypted.txt" << endl;
        cin >> outNameFile;

        ofstream outfile(outNameFile);
        if (!outfile) {
            cerr << "Файл не может открыться" << endl;
            return;
        }
        outfile << decrypted;
        outfile.close();

        cout << "Успешно создан файл с расшифрованным текстом: " << outNameFile << endl;

    } else {
        cout << "Некорректный ввод" << endl;
    }
}
void atbashAsciiFunct(string& inNameFile, int choice) {
    string text, NameFile, outNameFile;

    ifstream infile(inNameFile, ios::binary);
    if (!infile) {
        cerr << "Ошибка: не удалось открыть файл: " << inNameFile << endl;
        return;
    }

    char symbol;
    while (infile.get(symbol)) {
        text += symbol;
    }
    infile.close();

    string result = atbashAll(text);

    if (choice == 1) {
        cout << "Введите название файла для зашифрованного текста (например: Encrypted_Atbash.bin): ";
        cin >> NameFile;

        ofstream outfile(NameFile, ios::binary);
        if (!outfile) {
            cerr << "Ошибка: не удалось создать файл: " << NameFile << endl;
            return;
        }
        outfile.write(result.c_str(), result.size());
        outfile.close();

        cout << "Успешно создан файл с зашифрованным текстом: " << NameFile << endl;

    } else if (choice == 2) {
        cout << "Введите название файла для расшифрованного текста (например: Decrypted_Atbash.txt): ";
        cin >> outNameFile;

        ofstream outfile(outNameFile);
        if (!outfile) {
            cerr << "Ошибка: не удалось создать файл: " << outNameFile << endl;
            return;
        }
        outfile << result;
        outfile.close();

        cout << "Успешно создан файл с расшифрованным текстом: " << outNameFile << endl;

    } else {
        cout << "Ошибка: некорректный выбор режима." << endl;
    }
}
