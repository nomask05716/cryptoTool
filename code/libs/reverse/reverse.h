#pragma once
#include <string>
std::string reverseEncrypt(const std::string& text, const std::string& key);
std::string reverseDecrypt(const std::string& text, const std::string& key);
void reverseAsciiFunct(std::string& inNameFile, int choice, std::string& key);