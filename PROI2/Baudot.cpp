#include "pch.h"
#include "Baudot.h"
#include <string>
#include <iostream>
#include <algorithm>

Baudot::Baudot()
{

}
Baudot::~Baudot()
{
}

std::string Baudot::decodeOneCharacter(std::string strEncrypted) {

	std::string eCharacter;

	if (strEncrypted == "00100")
		eCharacter.append(" ");
	else if (strEncrypted == "00011")
		eCharacter.append("A");
	else if (strEncrypted == "11001")
		eCharacter.append("B");
	else if (strEncrypted == "01110")
		eCharacter.append("C");
	else if (strEncrypted == "01001")
		eCharacter.append("D");
	else if (strEncrypted == "00001")
		eCharacter.append("E");
	else if (strEncrypted == "01101")
		eCharacter.append("F");
	else if (strEncrypted == "11010")
		eCharacter.append("G");
	else if (strEncrypted == "10100")
		eCharacter.append("H");
	else if (strEncrypted == "00110")
		eCharacter.append("I");
	else if (strEncrypted == "01011")
		eCharacter.append("J");
	else if (strEncrypted == "01111")
		eCharacter.append("K");
	else if (strEncrypted == "10010")
		eCharacter.append("L");
	else if (strEncrypted == "11100")
		eCharacter.append("M");
	else if (strEncrypted == "01100")
		eCharacter.append("N");
	else if (strEncrypted == "11000")
		eCharacter.append("O");
	else if (strEncrypted == "10110")
		eCharacter.append("P");
	else if (strEncrypted == "10111")
		eCharacter.append("Q");
	else if (strEncrypted == "01010")
		eCharacter.append("R");
	else if (strEncrypted == "00101")
		eCharacter.append("S");
	else if (strEncrypted == "10000")
		eCharacter.append("T");
	else if (strEncrypted == "00111")
		eCharacter.append("U");
	else if (strEncrypted == "11110")
		eCharacter.append("V");
	else if (strEncrypted == "10011")
		eCharacter.append("W");
	else if (strEncrypted == "11101")
		eCharacter.append("X");
	else if (strEncrypted == "10101")
		eCharacter.append("Y");
	else if (strEncrypted == "10001")
		eCharacter.append("Z");

	return eCharacter;
};

std::string Baudot::convertToBaudotCode(std::string userInput) {
	
	int messageLength = 0;
	std::string ita2;

	messageLength = userInput.length();
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

	for (int i = 0; i < messageLength; i++)
	{
		switch (userInput[i])
		{
		case ' ':	ita2.append("00100"); break;
		case 'A':	ita2.append("00011"); break;
		case 'B':	ita2.append("11001"); break;
		case 'C':	ita2.append("01110"); break;
		case 'D':	ita2.append("01001"); break;
		case 'E':	ita2.append("00001"); break;
		case 'F':	ita2.append("01101"); break;
		case 'G':	ita2.append("11010"); break;
		case 'H':	ita2.append("10100"); break;
		case 'I':	ita2.append("00110"); break;
		case 'J':	ita2.append("01011"); break;
		case 'K':	ita2.append("01111"); break;
		case 'L':	ita2.append("10010"); break;
		case 'M':	ita2.append("11100"); break;
		case 'N':	ita2.append("01100"); break;
		case 'O':	ita2.append("11000"); break;
		case 'P':	ita2.append("10110"); break;
		case 'Q':	ita2.append("10111"); break;
		case 'R':	ita2.append("01010"); break;
		case 'S':	ita2.append("00101"); break;
		case 'T':	ita2.append("10000"); break;
		case 'U':	ita2.append("00111"); break;
		case 'V':	ita2.append("11110"); break;
		case 'W':	ita2.append("10011"); break;
		case 'X':	ita2.append("11101"); break;
		case 'Y':	ita2.append("10101"); break;
		case 'Z':	ita2.append("10001"); break;
		default: break;
		}
	}
	return ita2;
};

std::string Baudot::baudotCodeToAscii(std::string baudotCode) {

	std::string asciiCode = "";
	std::string eCharacter;
	int numberOfBits = 0;
	int lenght = baudotCode.length();
		for (int i = 0; i <= lenght; i++) {
		
		numberOfBits++;
		eCharacter += baudotCode[i];

		if (numberOfBits == 5) {
			numberOfBits = 0;
			asciiCode += decodeOneCharacter(eCharacter);
			eCharacter = "";
		}
	}
	return asciiCode;
};

