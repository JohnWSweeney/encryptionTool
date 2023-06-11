#include "start.h"

int main()
{
	std::cout << "encryptionTool v0.0.2\n\n";

	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		startMenu(running, tokens);
	}
}