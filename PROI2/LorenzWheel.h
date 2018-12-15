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
	void initializeWheel(std::string pinSettings);
	void setPinPosition(int pinPositionToSet);

private:
	Node *currentNode;
	
};

