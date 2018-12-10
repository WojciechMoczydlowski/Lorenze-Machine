#include "LorenzWheel.h"
#include <string>
#pragma once
class LorenzMachine
{
public:
	LorenzMachine();
	~LorenzMachine();

	std::string codeMessage(std::string message);
	std::string decodeMessage(std::string message);
private:

	LorenzWheel CollectionOfWheelsK[5];
	LorenzWheel CollectionOfWheelsS[5];
	LorenzWheel WheelM1;
	LorenzWheel WheelM2;


	void rotateAllWheels();
	void initializeAllWheels(int *initialPositionOfAllWheels);
};

