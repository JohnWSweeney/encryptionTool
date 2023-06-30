#include "defaultPRNG.h"

int defaultPRNG = 4;

void prngQuery()
{
	if (defaultPRNG == 0)
	{
		std::cout << "PRNG: User-seeded rand.\n\n";
	}
	else if (defaultPRNG == 4)
	{
		std::cout << "PRNG: User-seeded 32-bit Mersenne Twister.\n\n";
	}
	else if (defaultPRNG == 6)
	{
		std::cout << "PRNG: User-seeded 64-bit Mersenne Twister.\n\n";
	}
}

void prngStatus(std::vector<std::string> &tokens)
{
	if (tokens[1] == "query")
	{
		prngQuery();
	}
	else if (tokens[1] == "set")
	{
		if (tokens[2] == "rand")
		{
			defaultPRNG = 0;
			prngQuery();
		}
		else if (tokens[2] == "mt32")
		{
			defaultPRNG = 4;
			prngQuery();
		}
		else if (tokens[2] == "mt64")
		{
			defaultPRNG = 6;
			prngQuery();
		}
		else
		{
			std::cout << "Invalid PRNG type.\n\n";
		}
	}
	else
	{
		std::cout << "Invalid command.\n\n";
	}
}