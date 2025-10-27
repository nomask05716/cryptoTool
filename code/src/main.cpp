#include <iostream>
#include <bitset>
#include <clocale>
#ifndef NOMINMAX
    #define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif

#ifdef _WIN32
    #include <windows.h>
    #undef byte 
#endif
#include "cryptoLibs.h"
using namespace std;

enum mainMenu {
    encryptDecryptText = 1,
    encryptDecryptFile,  
};

enum subMenu {
    caesar = 1,
    reverseAscii,
    atbashAscii,
};

enum choosingAction {
    encrypt = 1,
    decrypt,
};

string stringToBinary(const string& input) {
    string binary;
    for (unsigned char symbol : input) {
        binary += bitset<8>(symbol).to_string();
    }
    return binary;
}

string binaryToString(const string& binary) {
    string output;
    if (binary.size() % 8 != 0) {
        cerr << "Ошибка: длина бинарной строки не кратна 8\n";
        return "";
    }
    for (size_t i = 0; i < binary.size(); i += 8) {
        bitset<8> byte(binary.substr(i, 8));
        output += static_cast<char>(byte.to_ulong());
    }
    return output;
}

int main() {
    int choiceMainMenu, choiceSubMenu;
    bool running = true; 

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif

    while (running) {  
        choiceMainMenu = ValidInputMainMenu();

        switch (choiceMainMenu) {
            case encryptDecryptText: {
                choiceSubMenu = ValidInputSubMenu();
                switch (choiceSubMenu) {
                    case caesar: {
                        string inputText, input, output;
                        int shift = validInputKeyCaesar();
                        while (true) {
                            cout << "Введите текст: ";
                            getline(cin, inputText);
                            if (!(inputText.empty())) {
                                break;
                            }
                        }
                        int choice = ValidInputAction();
                        switch (choice) {
                            case encrypt: {
                                output = caesarEncrypt(inputText, shift);
                                output = stringToBinary(output);
                                cout << "Зашифрованный текст: " << output << endl;
                                break;
                            }
                            case decrypt: {
                                input = binaryToString(inputText);
                                output = caesarDecrypt(input, shift);
                                cout << "Расшифрованный текст: " << output << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case reverseAscii: {
                        string inputText, output, shift = validInputKey();
                        while (true) {
                            cout << "Введите текст: ";
                            getline(cin, inputText);
                            if (!(inputText.empty())) {
                                break;
                            }
                        }
                        int choice = ValidInputAction();
                        switch (choice) {
                            case encrypt: {
                                output = reverseEncrypt(inputText, shift);
                                cout << "Зашифрованный текст: " << output << endl;
                                break;
                            }
                            case decrypt: {
                                output = reverseDecrypt(inputText, shift);
                                cout << "Расшифрованный текст: " << output << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case atbashAscii: {
                        string inputText, input, output;
                        while (true) {
                            cout << "Введите текст: ";
                            getline(cin, inputText);
                            if (!(inputText.empty())) {
                                break;
                            }
                        }
                        int choice = ValidInputAction();
                        if (choice == encrypt) {
                            output = atbashUniversal(inputText);
                            cout << "Зашифрованный текст: " << output << endl;
                        } else {
                            output = atbashUniversal(inputText);
                            cout << "Расшифрованный текст: " << output << endl;
                        }
                    break;
                    }
                }
                break;
            }
            case encryptDecryptFile: {
                choiceSubMenu = ValidInputSubMenu();
                switch (choiceSubMenu) {
                    case caesar: {
                        int shift = validInputKeyCaesar(), choice = ValidInputAction();
                        string pathFile = validInputPathFile();
                        codeCaesar(pathFile, shift, choice);
                        break;
                    }
                    case reverseAscii: {
                        int choice = ValidInputAction();
                        string pathFile = validInputPathFile(), shift = validInputKey();
                        reverseAsciiFunct(pathFile, choice, shift);
                        break;
                    }
                    case atbashAscii: {
                        int choice = ValidInputAction();
                        string pathFile = validInputPathFile();
                        atbashAsciiFunct(pathFile, choice);
                        break;
                    }
                }
                break;
            }
            
        }
        char continueChoice;
        cout << "Хотите продолжить? (y/n): ";
        cin >> continueChoice;
        cin.ignore(); 
        if (continueChoice != 'y' && continueChoice != 'Y') {
            running = false;
            cout << "Выход из программы..." << endl;
        }
        
    }

    return 0;
}