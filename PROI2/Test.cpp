#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Test.h"
#include "LorenzMachine.h"
#include "LorenzWheel.h"
#include "Baudot.h"
#include "CycleList.h"
#include "Node.h"
Test::Test()
{
	message = "Message to testing";
	for (int i = 0; i < 12; i++) {
		pinSetting[i] = 0;
	}
}

Test::~Test()
{
}

void Test::test() {
	std::cout << "LorenzMachine:\n";

	std::cout << "myLorenzMachine.codeMessage(message, pinSetting):\n";
	myLorenzMachine.codeMessage(message, pinSetting);
	system("pause");


	std::cout << "\nLorenzWheel:\n";

	std::cout << "myLorenzWheel.addNode(true)\n";
	myLorenzWheel.addNode(true);
	system("pause");

	std::cout << "currentNode = myLorenzWheel.getCurrentNode()\n";
	Node *currentNode;
	currentNode = myLorenzWheel.getCurrentNode();
	system("pause");

	std::cout << "currentNode = myLorenzWheel.getHead()\n";
	currentNode = myLorenzWheel.getHead();
	system("pause");

	std::cout << "myLorenzWheel.initializeWheel(10101001001110)\n";
	myLorenzWheel.initializeWheel("10101001001110");
	system("pause");

	std::cout << "myLorenzWheel.resetWheel()\n";
	myLorenzWheel.resetWheel();
	system("pause");

	std::cout << "myLorenzWheel.rotateWheel()\n";
	myLorenzWheel.rotateWheel();
	system("pause");


	std::cout << "myLorenzWheel.setHead(currentNode))\n";
	myLorenzWheel.setHead(currentNode);
	system("pause");


	std::cout << "myLorenzWheel.setHead(currentNode))\n";
	myLorenzWheel.setPinPosition(5);
	system("pause");
	

	std::cout << "Node:\n";

	std::cout << "myNode.getNext()\n";
	myNode.getNext();
	system("pause");

	std::cout << "myNode.getPrev()\n";
	myNode.getPrev();
	system("pause");

	std::cout << "myNode.getValue()\n";
	myNode.getValue();
	system("pause");

	std::cout << "myNode.setNext(currentNode)\n";
	myNode.setNext(currentNode);
	system("pause");

	std::cout << "myNode.setPrev(currentNode)\n";
	myNode.setPrev(currentNode);
	system("pause");

	std::cout << "myNode.setValue(true)\n";
	myNode.setValue(true);
	system("pause");

	
	std::cout << "Baudot:\n";

	std::cout << "myBaudot.baudotCodeToAscii(10001);\n";
	myBaudot.baudotCodeToAscii("10001");
	system("pause");

	std::cout << "myBaudot.convertToBaudotCode(wojtek);n";
	myBaudot.convertToBaudotCode("wojtek");
	system("pause");
}