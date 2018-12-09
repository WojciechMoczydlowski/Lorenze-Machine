#include "CycleList.h"
#include "Node.h"
#pragma once
class LorenzWheel : public CycleList
{

public:
	LorenzWheel();
	~LorenzWheel();

	void setPinPosition(int pinPositionToSet);

	Node* getCurrentNode() { return currentNode; }

	void rotateWheel();

	void resetWheel();


private:
	Node *currentNode;
};

