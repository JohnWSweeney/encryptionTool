#include "functions.h"
#include "cipherFunctions.h"

void encryptFunction(std::vector<std::string> &tokens)
{
	bool encryptBool = true;
	try {
		int key = std::stoi(tokens[1]);
		if (key < 0 || key > 32767)
		{
			throw 20;
		}

		std::string msg = tokens[2];
		for (int i = 3; i < tokens.size(); i++)
		{
			msg = msg + " " + tokens[i];
		}
		std::cout << "\nmessage: \t" << msg << '\n';
		std::string cipherText;
		encryptDecrypt(msg, key, encryptBool, cipherText);
		std::cout << "cipherText: \t" << cipherText << "\n\n";
	}
	catch (std::invalid_argument)
	{
		std::cout << "Key must be a positive integer.\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Key must be an integer between 0 and 32767.\n";
	}
	catch (int e)
	{
		std::cout << "Key must be an integer between 0 and 32767.\n";
	}
}

void decryptFunction(std::vector<std::string> &tokens)
{
	bool encryptBool = false;
	try {
		int key = std::stoi(tokens[1]);
		if (key < 0 || key > 32767)
		{
			throw 20;
		}
	}
	catch (std::invalid_argument)
	{
		std::cout << "Key must be a positive integer.\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Key must be an integer between 0 and 32767.\n";
	}
	catch (int e)
	{
		std::cout << "Key must be an integer between 0 and 32767.\n";
	}
}

void loop(std::vector<std::string> &tokens)
{
	try {
		int key = std::stoi(tokens[1]);
		if (key < 0 || key > 32767)
		{
			throw 20;
		}

		std::string msg = tokens[2];
		for (int i = 3; i < tokens.size(); i++)
		{
			msg = msg + " " + tokens[i];
		}
		std::cout << "\nmessage: \t" << msg << '\n';
		std::string cipherText, plainText;
		// encrypt message.
		encryptDecrypt(msg, key, true, cipherText);
		std::cout << "cipherText: \t" << cipherText << '\n';
		// decrypt message.
		encryptDecrypt(cipherText, key, false, plainText);
		std::cout << "plainText: \t" << plainText << "\n\n";
	}
	catch (std::invalid_argument)
	{
		std::cout << "Key must be a positive integer.\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Key must be an integer between 0 and 32767.\n";
	}
	catch (int e)
	{
		std::cout << "Key must be an integer between 0 and 32767.\n";
	}
}