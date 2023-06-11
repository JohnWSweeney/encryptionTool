#pragma once
#include <iostream>
#include <vector>

char findReplaceChar(std::vector<char> charVector, char testChar, bool shiftRight, int shiftPlaces);
void encryptDecrypt(std::string message, int key, bool encryptBool, std::string &text);