#include "pch.h"
#include "LorenzMachine.h"
#include "Baudot.h"
#include <string>

LorenzMachine::LorenzMachine()
{
	for (int i = 0; i < 12; i++) {
		initialPositionOfAllWheels[i] = 0;
	}
}


LorenzMachine::~LorenzMachine()
{
}



std::string LorenzMachine::codeMessage(std::string message) {

	Baudot myBaudotConvereter;

	std::string messageInBaudot = myBaudotConvereter.convertToBaudotCode(message);
	std::string encryptedMessageInBaudot="";
	std::string encryptedMessageInAscii="";

	bool key[5];
	char  oneCharacter[5];

	int lenghtOfMessage = (int)message.length();
	int breakPoint = 0;

	for (int i = 0; i < lenghtOfMessage; i++) {
		if (breakPoint == 5) {
			breakPoint = 0;

			for (int j = 0; j < 5; j++) {

			}

		}
		else {
			key[breakPoint] = CollectionOfWheelsK[breakPoint].getCurrentNode()->getValue() ^ CollectionOfWheelsS[breakPoint].getCurrentNode()->getValue();
			oneCharacter[breakPoint] = messageInBaudot[i];
			breakPoint++;
		}
	}
	return "";
};

std::string LorenzMachine::decodeMessage(std::string message) {

		bool key[5];

	return "";
};

void LorenzMachine::rotateAllWheels() {

};

void LorenzMachine::initializeAllWheels(int *initialPositionOfAllWheels) {

	
	std::string pinSetting = "110010000011111110101001001001101010111011011011101001111110010000000001010001101100000010010110001111100010101100011110001011101000100011111111111010000010010101010111001000010100101100001101011101101011011001000110111111010000000110110000010101100100010000111000100111100110001110111101010011001011010011011010011110111101111001001001010111110001101000100011101001011000110100001101011000000110110110100100110111101011101111000000101000111001100010110000100110001001000101011001001110111010001011110";
	
	CollectionOfWheelsK[0].initializeWheel(initialPositionOfAllWheels[0], pinSetting.substr(0, 43));
	CollectionOfWheelsK[1].initializeWheel(initialPositionOfAllWheels[1], pinSetting.substr(44, 90));
	CollectionOfWheelsK[2].initializeWheel(initialPositionOfAllWheels[2], pinSetting.substr(91, 141));
	CollectionOfWheelsK[3].initializeWheel(initialPositionOfAllWheels[3], pinSetting.substr(142, 194));
	CollectionOfWheelsK[4].initializeWheel(initialPositionOfAllWheels[4], pinSetting.substr(195, 253));

	WheelM1.initializeWheel(initialPositionOfAllWheels[5], pinSetting.substr(254, 290));;
	WheelM2.initializeWheel(initialPositionOfAllWheels[6], pinSetting.substr(291, 351));;

	CollectionOfWheelsS[0].initializeWheel(initialPositionOfAllWheels[0], pinSetting.substr(352, 392));
	CollectionOfWheelsS[1].initializeWheel(initialPositionOfAllWheels[1], pinSetting.substr(393, 423));
	CollectionOfWheelsS[2].initializeWheel(initialPositionOfAllWheels[2], pinSetting.substr(424, 452));
	CollectionOfWheelsS[3].initializeWheel(initialPositionOfAllWheels[3], pinSetting.substr(453, 478));
	CollectionOfWheelsS[4].initializeWheel(initialPositionOfAllWheels[4], pinSetting.substr(479, 501));
	
};