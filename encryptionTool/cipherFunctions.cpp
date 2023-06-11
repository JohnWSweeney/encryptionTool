#include "cipherFunctions.h"
#include "characters.h"

char findReplaceChar(std::vector<char> charVector, char testChar, bool shiftRight, int shiftPlaces)
{
	int testCharLocation, newCharLocation, remainder;
	auto result = std::find(charVector.begin(), charVector.end(), testChar);
	if (result != charVector.end())
	{
		testCharLocation = std::distance(charVector.begin(), result);
	}
	//else
	//{
		// what here?
	//}

	if (shiftRight == 0)
	{
		if (testCharLocation - shiftPlaces < 0)
		{
			remainder = shiftPlaces - testCharLocation;
			newCharLocation = charVector.size() - remainder;
			return charVector[newCharLocation];
		}
		else
		{
			newCharLocation = testCharLocation - shiftPlaces;
			return charVector[newCharLocation];
		}
	}
	else
	{
		if (testCharLocation + shiftPlaces > (charVector.size() - 1))
		{
			remainder = charVector.size() - testCharLocation;
			newCharLocation = shiftPlaces - remainder;
			return charVector[newCharLocation];
		}
		else
		{
			newCharLocation = testCharLocation + shiftPlaces;
			return charVector[newCharLocation];
		}
	}
}

void encryptDecrypt(std::string message, int key, bool encryptBool, std::string &text)
{
	const char *msgPtr = message.c_str();
	srand(key);
	for (int i = 0; i < message.length(); i++)
	{
		int temp = rand();
		int mod2 = temp % 2;
		int rando = ((double)temp / RAND_MAX) * (charVector.size() - 1) + 1;
		if (encryptBool == false)
		{
			mod2 = 1 - mod2;
		}
		char tempChar = findReplaceChar(charVector, msgPtr[i], mod2, rando);
		text.push_back(tempChar);
	}
}