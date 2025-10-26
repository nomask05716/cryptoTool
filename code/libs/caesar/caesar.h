#pragma once
#include <string>
std::string caesarEncrypt(const std::string& text, int shift);
std::string caesarDecrypt(const std::string& text, int shift);
void codeCaesar(std::string& inNameFile, int shift, int choice);