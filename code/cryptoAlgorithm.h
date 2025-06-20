#pragma once
using namespace std;
string caesarEncrypt(const string& text, int shift);
string caesarDecrypt(const string& text, int shift);
string reverseEncrypt(const string& text, const string& key);
string reverseDecrypt(const string& text, const string& key);
char atbashLatin(char ch);
char atbashCyrillic(char ch);
char atbashSymbol(char ch);
string atbashAll(const string& text);
void codeCaesar(string& inNameFile,int shift,int choice);
void reverseAsciiFunct(string& inNameFile, int choice,string& key);
void atbashAsciiFunct(string& inNameFile, int choice);
