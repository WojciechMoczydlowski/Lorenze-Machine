#include "CycleList.h"
#include "Node.h"
#include <string>
#pragma once
class LorenzWheel : public CycleList
{

public:
	LorenzWheel();
	~LorenzWheel();

	

	Node* getCurrentNode() { return currentNode; }

	void rotateWheel();
	void resetWheel();
	void initializeWheel(int pinPosition, std::string pinSettings);


private:
	Node *currentNode;
	void setPinPosition(int pinPositionToSet);
};

