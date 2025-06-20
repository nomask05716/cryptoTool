#include <iostream>
#include <bitset>
#include "cryptoAlgorithm.h"
#include "validInput.h"
using namespace std;
enum mainMenu{
    encryptDecryptText =1,
    encryptDecryptFile,
};
enum subMenu{
    caesar=1,
    reverseAscii,
    atbashAscii,
};
enum choosingAction{
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
int main(){
    int choiceMainMenu,choiceSubMenu;
    choiceMainMenu = ValidInputMainMenu();
    switch (choiceMainMenu)
    {
    case encryptDecryptText:{
        choiceSubMenu = ValidInputSubMenu();
        switch (choiceSubMenu)
        {
        case caesar:{
            string inputText,input,output;
            int shift = validInputKeyCaesar();
            cin.ignore();
            while (true){
                cout << "Введите текст: ";
                getline(cin, inputText);
                if (!(inputText.empty())){
                    break;
                }
            }
            int choice = ValidInputAction();
            switch (choice){
                case encrypt:{
                    output = caesarEncrypt(inputText,shift);
                    output = stringToBinary(output);
                    cout << "\nЗашифрованный текст: " << output << endl;
                    break;
                }
                case decrypt:{
                    input = binaryToString(inputText);
                    output = caesarDecrypt(input,shift);
                    cout << "Расшифрованный текст: " << output << endl;
                    break;
                }
            }
            
            break;
        }
        case reverseAscii:{
            string inputText,output,shift = validInputKey();
            while (true){
                cout << "Введите текст: ";
                getline(cin, inputText);
                if (!(inputText.empty())){
                    break;
                }
            }
            int choice = ValidInputAction();
            switch(choice){
                case encrypt:{
                    output = reverseEncrypt(inputText, shift);
                    cout << "\nЗашифрованный текст: " << output << endl;
                    break;
                }
                case decrypt:{
                    output = reverseDecrypt(inputText, shift);
                    cout << "Расшифрованный текст: " << output << endl;
                    break;
                }
            }
            break;
        }
        case atbashAscii:{
            string inputText,input,output;
            while (true){
                cout << "Введите текст: ";
                getline(cin, inputText);
                if (!(inputText.empty())){
                    break;
                }
            }
            int choice = ValidInputAction();
            switch (choice){
                case encrypt:{
                    output = atbashAll(inputText);
                    output = stringToBinary(output);
                    cout << "\nЗашифрованный текст: " << output << endl;
                    break;
                }
                case decrypt:{
                    input = binaryToString(inputText);
                    output = atbashAll(input);
                    cout << "Расшифрованный текст: " << output << endl;
                    break;
                }
            }
            break;
        }
        }
        break;
    }
    case encryptDecryptFile:
        choiceSubMenu = ValidInputSubMenu();
        switch (choiceSubMenu)
        {
        case caesar:{
            int shift = validInputKeyCaesar(),choice = ValidInputAction();
            string pathFile = validInputPathFile();
            codeCaesar(pathFile,shift,choice);
            break;
            }
        case reverseAscii:{
            int choice = ValidInputAction();
            string pathFile = validInputPathFile(),shift = validInputKey();
            reverseAsciiFunct(pathFile,choice,shift);
            break;
            }
        case atbashAscii:{
            int choice = ValidInputAction();
            string pathFile = validInputPathFile();
            atbashAsciiFunct(pathFile,choice);
            break;
            }
        }
        break;
    }
    return 0;
}