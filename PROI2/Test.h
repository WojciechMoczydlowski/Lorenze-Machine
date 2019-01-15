#include "LorenzMachine.h"
#include "LorenzWheel.h"
#include "Baudot.h"
#include "CycleList.h"
#include "Node.h"
#pragma once
class Test
{
public:
	Test();
	~Test();
	void test();

private:

	LorenzMachine myLorenzMachine;
	LorenzWheel myLorenzWheel;
	Baudot myBaudot;
	CycleList myCycleList;
	Node myNode;
	
	std::string message;
	int pinSetting[12];
};

