#include "start.h"
#include "functions.h"
#include "defaultPRNG.h"

void getInput(std::vector<std::string> &tokens)
{
	tokens.clear();
	// Tokenize user input.
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void startMenu(bool &running, std::vector<std::string> &tokens)
{
	// 
	if (tokens[0] == "encrypt")
	{
		encryptFunction(tokens);
	}
	else if (tokens[0] == "decrypt")
	{
		//decryptFunction(tokens);
	}
	else if (tokens[0] == "loop")
	{
		loop(tokens);
	}
	// Select pseudorandom number generator function.
	else if (tokens[0] == "default")
	{
		prngStatus(tokens);
	}
	// Close app.
	else if (tokens[0] == "exit")
	{
		running = false;
	}
	// Reject all other inputs.
	else
	{
		std::cout << "Invalid function command.\n";
	}
}