#include "cipherFunctions.h"
#include "random.h"
#include "defaultPRNG.h"
#include "characters.h"

char findReplaceChar(std::vector<char> charVector, char testChar, bool shiftRight, int shiftNumPlaces)
{
	int testCharLocation, newCharLocation, remainder;
	auto result = std::find(charVector.begin(), charVector.end(), testChar);
	if (result != charVector.end())
	{
		testCharLocation = std::distance(charVector.begin(), result);
	}

	if (shiftRight == 0)
	{
		if (testCharLocation - shiftNumPlaces < 0)
		{
			remainder = shiftNumPlaces - testCharLocation;
			newCharLocation = charVector.size() - remainder;
			return charVector[newCharLocation];
		}
		else
		{
			newCharLocation = testCharLocation - shiftNumPlaces;
			return charVector[newCharLocation];
		}
	}
	else
	{
		if (testCharLocation + shiftNumPlaces > (charVector.size() - 1))
		{
			remainder = charVector.size() - testCharLocation;
			newCharLocation = shiftNumPlaces - remainder;
			return charVector[newCharLocation];
		}
		else
		{
			newCharLocation = testCharLocation + shiftNumPlaces;
			return charVector[newCharLocation];
		}
	}
}

void encryptDecrypt(std::string message, int seed, bool encryptBool, std::string &text)
{
	const char *msgPtr = message.c_str();
	random rando;
	rando.setSeed(defaultPRNG, seed);
	for (int i = 0; i < message.length(); i++)
	{
		bool shiftRight = rando.getNum(defaultPRNG, 0, 1);
		int shiftNumPlaces = rando.getNum(defaultPRNG, 0, charVector.size() - 1);
		if (encryptBool == false)
		{
			shiftRight = 1 - shiftRight;
		}
		char tempChar = findReplaceChar(charVector, msgPtr[i], shiftRight, shiftNumPlaces);
		text.push_back(tempChar);
	}
}