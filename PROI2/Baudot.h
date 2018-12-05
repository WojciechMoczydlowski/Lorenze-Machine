#pragma once
#include <string>
class Baudot
{
public:
	Baudot();
	~Baudot();

	std::string convertToBaudotCode(std::string userInput);
	std::string baudotCodeToAscii(std::string strEncrypted);
private:
	std::string decodeOneCharacter(std::string strEncrypted);
};

