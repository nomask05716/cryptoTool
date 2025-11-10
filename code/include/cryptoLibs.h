#pragma once
#include <string>
std::string caesarEncrypt(const std::string& text, int shift);
std::string caesarDecrypt(const std::string& text, int shift);
void codeCaesar(std::string& inNameFile, int shift, int choice);
std::string reverseEncrypt(const std::string& text, const std::string& key);
std::string reverseDecrypt(const std::string& text, const std::string& key);
void reverseAsciiFunct(std::string& inNameFile, int choice, std::string& key);
std::string atbashUniversal(const std::string& text);
std::string atbashAll(const std::string& data);
void atbashAsciiFunct(std::string& inNameFile, int choice);
int validInputMainMenu();
int validInputSubMenu();
int validInputKeyCaesar();
int validInputAction();
std::string validInputKey();
std::string validInputPathFile();
