#include "LorenzWheel.h"
#include <string>
#pragma once
class LorenzMachine
{
public:
	LorenzMachine();
	~LorenzMachine();

	std::string codeMessage(std::string message,int *pinSettings);
private:

	LorenzWheel CollectionOfWheelsK[5];
	LorenzWheel CollectionOfWheelsS[5];
	LorenzWheel WheelM1;
	LorenzWheel WheelM2;

	void rotateAllWheels();
	void setPinPositionOfAllWheels(int *initialPositionOfAllWheels);
};

