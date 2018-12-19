#include "pch.h"
#include "LorenzMachine.h"
#include "Baudot.h"
#include <string>
#include <iostream>

LorenzMachine::LorenzMachine()
{
	std::string pinSetting = "110010000011111110101001001001101010111011011011101001111110010000000001010001101100000010010110001111100010101100011110001011101000100011111111111010000010010101010111001000010100101100001101011101101011011001000110111111010000000110110000010101100100010000111000100111100110001110111101010011001011010011011010011110111101111001001001010111110001101000100011101001011000110100001101011000000110110110100100110111101011101111000000101000111001100010110000100110001001000101011001001110111010001011110";

	CollectionOfWheelsK[0].initializeWheel(pinSetting.substr(0, 43));
	CollectionOfWheelsK[1].initializeWheel(pinSetting.substr(44, 90));
	CollectionOfWheelsK[2].initializeWheel(pinSetting.substr(91, 141));
	CollectionOfWheelsK[3].initializeWheel(pinSetting.substr(142, 194));
	CollectionOfWheelsK[4].initializeWheel(pinSetting.substr(195, 253));

	WheelM1.initializeWheel(pinSetting.substr(254, 290));;
	WheelM2.initializeWheel(pinSetting.substr(291, 351));;

	CollectionOfWheelsS[0].initializeWheel(pinSetting.substr(352, 392));
	CollectionOfWheelsS[1].initializeWheel(pinSetting.substr(393, 423));
	CollectionOfWheelsS[2].initializeWheel(pinSetting.substr(424, 452));
	CollectionOfWheelsS[3].initializeWheel(pinSetting.substr(453, 478));
	CollectionOfWheelsS[4].initializeWheel(pinSetting.substr(479, 501));
}

LorenzMachine::~LorenzMachine()
{

}

std::string LorenzMachine::codeMessage(std::string message,int *pinSettings) {


	setPinPositionOfAllWheels(pinSettings);
	Baudot baudotToCodeMessage;

	std::string messageInBaudot = baudotToCodeMessage.convertToBaudotCode(message);
	std::string encryptedMessageInBaudot="";
	std::string encryptedMessageInAscii="";

	bool key[5];
	char  oneCharacter[5];

	int lenghtOfMessageInBaudot = (int)messageInBaudot.length();
	int breakPoint;
	//std::cout<< lenghtOfMessageInBaudot<< "\n"  ;
	for (int i = 0; i < lenghtOfMessageInBaudot; i++) {

		breakPoint = i % 5;
		//std::cout<< "\n" << breakPoint ;

		key[breakPoint] = CollectionOfWheelsK[breakPoint].getCurrentNode()->getValue() ^ CollectionOfWheelsS[breakPoint].getCurrentNode()->getValue();
		oneCharacter[breakPoint] = messageInBaudot[i];

		if (breakPoint == 4){
		/*	std::cout << "\n";*/
			for (int j = 0; j < 5; j++) {
				/*if (key[j])std::cout << "1";
				else std::cout << "0";*/
				bool keyToXor;
				if (oneCharacter[j] == '0') { keyToXor = false; }
				else { keyToXor = true; }
				if (key[j] ^ keyToXor) {encryptedMessageInBaudot.append("1");}
				else {encryptedMessageInBaudot.append("0");}
			}
			rotateAllWheels();
			std::cout << " ";
		}
	}
	encryptedMessageInAscii = baudotToCodeMessage.baudotCodeToAscii(encryptedMessageInBaudot);

	//std::cout <<"\n"<<"message  " << message<< "\n";
	//std::cout << "messageInBaudot  " << messageInBaudot << "\n";
	//std::cout << "encryptedMessageInBaudot  " << encryptedMessageInBaudot << "\n";
	//std::cout << "encryptedMessageInAscii  " << encryptedMessageInAscii << "\n";
	return encryptedMessageInAscii;
};

void LorenzMachine::rotateAllWheels() {
	for (int i = 0; i < 5; i++) {
		CollectionOfWheelsK[i].rotateWheel();
	}
	WheelM1.rotateWheel();
	if (WheelM1.getCurrentNode()->getValue()) {
		WheelM2.rotateWheel();
	}
	bool shouldRotateWheelsS = WheelM1.getCurrentNode()->getValue() ^ WheelM2.getCurrentNode()->getValue();
	if (shouldRotateWheelsS) {
		for (int i = 0; i < 5; i++) {
			CollectionOfWheelsS[i].rotateWheel();
		}
	}
};

void LorenzMachine::setPinPositionOfAllWheels(int *initialPositionOfAllWheels) {

	for (int i = 0; i < 5; i++) {
		CollectionOfWheelsK[i].setPinPosition(initialPositionOfAllWheels[i]);
	}
	
	WheelM1.setPinPosition(initialPositionOfAllWheels[5]);
	WheelM2.setPinPosition(initialPositionOfAllWheels[6]);

	for (int i = 0; i < 5; i++) {
		CollectionOfWheelsS[i].setPinPosition(initialPositionOfAllWheels[i+7]);
	}
};