#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "cryptoAlgorithm.h"
#include <codecvt>
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


string reverseEncrypt(const string& text, const string& key) {
    string result = "";
    int keyLen = key.size();
    for (int i = 0; i < static_cast<int>(text.size()); ++i) {
        int shifted = static_cast<int>(text[i]) + static_cast<int>(key[i % keyLen]);
        string ascii = to_string(shifted);
        reverse(ascii.begin(), ascii.end());
        result += ascii + " ";
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
        ascii -= static_cast<int>(key[index % keyLen]);
        result += static_cast<char>(ascii);
        index++;
    }
    return result;
}
char atbashLatin(char ch) {
    if (ch >= 97 && ch <= 122) { 
        return 122 - (ch - 97);  
    }
    if (ch >= 65 && ch <= 90) { 
        return 90 - (ch - 65);  
    }
    return ch;
}
char atbashCyrillic(char ch) {
    unsigned char ucharCh = static_cast<unsigned char>(ch);

    if (ucharCh >= 192 && ucharCh <= 223) {
        unsigned char result = 223 - (ucharCh - 192);
        return static_cast<char>(result);
    }
    if (ucharCh >= 224 && ucharCh <= 255) {
        unsigned char result = 255 - (ucharCh - 224);
        return static_cast<char>(result);
    }
    return ch;
}

char atbashSymbol(char ch) {
    if (ch >= 33 && ch <= 126) {
        char result = static_cast<char>(126 - (ch - 33));
        return result;
    }
    return ch;
}
string atbashAll(const string& text) {
    string result;
    for (char ch : text) {
        unsigned char uch = (unsigned char)ch;
        if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90)) {
            result += atbashLatin(ch);
        } else if (uch >= 192 && uch <= 255) {
            result += atbashCyrillic(ch);
        } else {
            result += atbashSymbol(ch);
        }
    }
    return result;
}