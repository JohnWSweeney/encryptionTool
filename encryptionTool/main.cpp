#include "functions.h"

int main()
{
	std::cout << "encryptionTool v1.0.0\n\n";

	std::string testStr = "The quick brown fox jumped over the lazy dog.";
	int key = 1;

	std::string cipherText, plainText;
	encryptDecrypt(testStr, key, true, cipherText);
	encryptDecrypt(cipherText, key, false, plainText);

	std::cout << testStr << '\n';
	std::cout << cipherText << '\n';
	std::cout << plainText << '\n';
}