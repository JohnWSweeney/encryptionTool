#include <iostream>
#include <vector>

struct characters
{
	std::vector<char> charVector = { 'a','b','c','d','e','f','g','h','i','j',
										'k','l','m','n','o','p','q','r','s','t',
										'u','v','w','x','y','z','A','B','C','D',
										'E','F','G','H','I','J','K','L','M','N',
										'O','P','Q','R','S','T','U','V','W','X',
										'Y','Z','1','2','3','4','5','6','7','8',
										'9','0','!','@','#','$','%','^','&','*',' ','.'};
};

char findChar(std::vector<char> charVector, char testChar, bool shiftRight, int shiftPlaces)
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

int main()
{
	std::cout << "encryptionTool v0.0.0\n\n";

	std::string testStr = "The quick brown fox jumped over the lazy dog.";
	int msgLen = testStr.length();
	const char *msgPtr = testStr.c_str();

	std::vector<char> cipherCharVector, decipherCharVector;

	int key = 1;
	int temp, mod2, mod72, rand72;
	characters src;

	// encrpyt testStr.
	srand(key);
	std::cout << "rand:" << "\t" << "mod2:" << "\t" << "rand72:" << "\t" << "char:" << "\t" << "cipherChar:" << '\n';
	for (int i = 0; i < msgLen; i++)
	{
		temp = rand();
		mod2 = temp % 2;
		mod72 = temp % 72;
		rand72 = ((double)temp / RAND_MAX) * 72;
		char cipherChar = findChar(src.charVector, msgPtr[i], mod2, rand72);
		cipherCharVector.push_back(cipherChar);
		std::cout << temp << '\t' << mod2 << '\t' << rand72 << '\t' << msgPtr[i] << '\t' << cipherChar << '\n';
	}
	std::cout << '\n';

	for (int i = 0; i < testStr.length(); i++)
	{
		std::cout << testStr[i];
	}
	std::cout << '\n';
	for (int i = 0; i < cipherCharVector.size(); i++)
	{
		std::cout << cipherCharVector[i];
	}
	std::cout << "\n";

	// encrpyt testStr.
	srand(key);
	for (int i = 0; i < cipherCharVector.size(); i++)
	{
		temp = rand();
		mod2 = temp % 2;
		rand72 = ((double)temp / RAND_MAX) * 72;
		char decipherChar = findChar(src.charVector, cipherCharVector[i], !mod2, rand72);
		decipherCharVector.push_back(decipherChar);
	}
	for (int i = 0; i < decipherCharVector.size(); i++)
	{
		std::cout << decipherCharVector[i];
	}
	std::cout << "\n\n";
}