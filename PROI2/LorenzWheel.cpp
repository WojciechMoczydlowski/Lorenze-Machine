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