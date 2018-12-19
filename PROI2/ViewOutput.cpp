#include "pch.h"
#include "ViewOutput.h"
#include <iostream> 
#include <string> 
#include <fstream>


ViewOutput::ViewOutput()
{
}


ViewOutput::~ViewOutput()
{

}
void ViewOutput::saveDataToFile(std::string message, int *pinPosition) {

	std::string nameOfFile;
	std::cout << "Enter name of file:";
	std::cin >> nameOfFile;
	std::ofstream myfile;
	myfile.open(nameOfFile);
	if (!myfile.is_open()) {
		std::cout << "We can not save data to this file";
		return;
	}
	else {
		myfile << message;
		myfile << "\n";
		for (int i = 0; i < 12; i++) {
			myfile << pinPosition[i];
			myfile << "\n";
		}
	myfile.close();
	}
};
void ViewOutput::showDataToConsole(std::string message) {
	if (message == "") {
		std::cout << "\nFirst you need to enter message! \n" << message;
	}
	else {
		std::cout << "This is your message:\n " << message;
	}
};