#include "pch.h"
#include "lorenzMachineSimulator.h"
#include <iostream>
#include <string>


lorenzMachineSimulator::lorenzMachineSimulator()
{
	message = "";
	for (int i = 0; i < 12; i++) {
		pinSetting[i] = 0;
	}
}


lorenzMachineSimulator::~lorenzMachineSimulator()
{
}


void lorenzMachineSimulator::simulate() {
	
	std::cout << "Welcome general!\n\n";
	std::cout << "This is your Lorenz Machine to encrypt secret message!\n";
	while (true) {
	std::cout << "Choose what do you want to do: \n";
	std::cout << "1.Enter message by keyboard.\n";
	std::cout << "2.Enter message from file.\n";
	std::cout << "3.Show my message.\n";
	std::cout << "4.Save message to file.\n";
	std::cout << "5.Code/decode my message.\n";
	std::cout << "6.Exit\n";

	int decisionNumber = 1;
	std::cin >> decisionNumber;

	if (decisionNumber == 1) myViewInput.getDataFromConsole(&message,pinSetting);
	else if (decisionNumber == 2) myViewInput.getDataFromFile(&message, pinSetting);
	else if (decisionNumber == 3) myViewOutput.showDataToConsole(message);
	else if (decisionNumber == 4) myViewOutput.saveDataToFile(message, pinSetting);
	else if (decisionNumber == 5) {
		if (message == "") return;
		else {
			message = myLorenzMachine.codeMessage(message, pinSetting);
		}
		std::cout << "Your message is coded!\n";
	}
	else return;
	std::cout << "\n";
	system("pause");
	system("cls");
	}
	
};