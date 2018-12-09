#include "pch.h"
#include "CycleList.h"
#include "Node.h"
#include <iostream>


CycleList::CycleList()
{
	head = nullptr;
}


CycleList::~CycleList()
{

}

void CycleList::setHead(Node * headToSet) {};

void CycleList::addNode(bool value) {
	
	if (head == nullptr) {
		head = new Node;
		head->setNext(head);
		head->setPrev(head);
		head->setValue(value);
	}
	else {
		Node *currentNode = head->getPrev();
		Node *nextNode = new Node;

		nextNode->setPrev(currentNode);
		nextNode->setNext(head);
		nextNode->setValue(value);

		currentNode->setNext(nextNode);
		head->setPrev(nextNode);
	}
};

void CycleList::deleteNode(Node * currentNode) {};