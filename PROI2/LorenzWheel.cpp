#include "pch.h"
#include "LorenzWheel.h"
#include <iostream>


LorenzWheel::LorenzWheel()
{
	currentNode = nullptr;
}

LorenzWheel::~LorenzWheel()
{
}


void LorenzWheel::setPinPosition(int pinPositionToSet) {

	if (getHead() == nullptr) return;
	currentNode = getHead();
	while (pinPositionToSet > 0) {
		currentNode = currentNode->getNext();
		pinPositionToSet--;
	}
}

void LorenzWheel::rotateWheel() {

	if (currentNode == nullptr) return;
	else currentNode = currentNode->getNext();
}

void LorenzWheel::resetWheel() {
	currentNode = getHead();
}

void LorenzWheel::initializeWheel(int pinPosition, std::string pinSettings) {
	
	setPinPosition(pinPosition);

	int sizeOfWheel = (int)pinSettings.length();

	for (int i = 0; i < sizeOfWheel; i++) {
		bool pin;
		if (pinSettings[i] == '0') pin = false;
		else pin = true;
		addNode(pin);
		}
};