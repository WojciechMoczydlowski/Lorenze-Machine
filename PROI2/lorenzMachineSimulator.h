#include "LorenzMachine.h"
#include "ViewInput.h"
#include "ViewOutput.h"
#include <iostream>
#include <string>
#pragma once
class lorenzMachineSimulator
{
public:
	lorenzMachineSimulator();
	~lorenzMachineSimulator();

	void simulate();
private:
	LorenzMachine myLorenzMachine;
	ViewInput myViewInput;
	ViewOutput myViewOutput;

	std::string message;
	std::string encryptedMessage;
	int pinSetting[12];
};

