#include "pch.h"
#include "ViewInput.h"
#include <iostream> 
#include <string> 
#include <fstream>

ViewInput::ViewInput()
{
}


void ViewInput::getDataFromConsole(std::string *message, int *pinPosition) {
	std::cout << "Enter message: ";
	std::getline(std::cin, *message);
	std::getline(std::cin, *message);
	std::cout << "Enter position of all Wheels: ";
		for (int i = 0; i < 12; i++) {
			std::cout << "\nWheel number " << i <<":";
			std::cin >> pinPosition[i];
	}
};
void ViewInput::getDataFromFile(std::string *message, int *pinPosition) {
	std::string nameOfFile;
	std::cout << "Enter name of file:";
	std::cin >> nameOfFile;
	std::ifstream myfile;
	myfile.open(nameOfFile);
	if (!myfile.is_open()) {
		std::cout << "We can not save data to this file";
		return;
	}
	else {
		std::getline(myfile, *message);
		for (int i = 0; i < 12; i++) {
			myfile >> pinPosition[i];
		}
		myfile.close();
		std::cout << *message << "\n";
		for (int i = 0; i < 12; i++) {
			std::cout << pinPosition[i]<< " ";
		}
	}

};