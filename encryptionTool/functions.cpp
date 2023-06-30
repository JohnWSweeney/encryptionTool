#include "functions.h"
#include "defaultPRNG.h"
#include "cipherFunctions.h"

void encryptFunction(std::vector<std::string> &tokens)
{
	bool encryptBool = true;
	try {
		int seed = std::stoi(tokens[1]);
		if (seed < 0 || seed > 32767)
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
		encryptDecrypt(msg, seed, encryptBool, cipherText);
		std::cout << "cipherText: \t" << cipherText << "\n\n";
	}
	catch (std::invalid_argument)
	{
		std::cout << "Seed must be a positive integer.\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Seed must be an integer between 0 and 32767.\n";
	}
	catch (int e)
	{
		std::cout << "Seed must be an integer between 0 and 32767.\n";
	}
}

void loop(std::vector<std::string> &tokens)
{
	try {
		int seed = std::stoi(tokens[1]);
		if (defaultPRNG == 0)
		{
			if (seed < 0 || seed > 32767)
			{
				throw 20;
			}
		}
		std::string msg = tokens[2];
		for (int i = 3; i < tokens.size(); i++)
		{
			msg = msg + " " + tokens[i];
		}
		std::cout << "\nmessage: \t" << msg << '\n';
		std::string cipherText, plainText;
		// encrypt message.
		encryptDecrypt(msg, seed, true, cipherText);
		std::cout << "cipherText: \t" << cipherText << '\n';
		// decrypt message.
		encryptDecrypt(cipherText, seed, false, plainText);
		std::cout << "plainText: \t" << plainText << "\n\n";
	}
	catch (std::invalid_argument)
	{
		std::cout << "Seed must be an integer.\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Seed integer is out of range.\n";
	}
	catch (int e)
	{
		std::cout << "Seed must be an integer between 0 and 32767.\n";
	}
}