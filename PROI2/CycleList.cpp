#include "pch.h"
#include "CycleList.h"
#include "Node.h"


CycleList::CycleList()
{
	head = nullptr;
	numberOfNodes = 0;
}


CycleList::~CycleList()
{

}

void CycleList::setNumberOfNodes(int numberOfNodesToSet) {};
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

		currentNode->setNext(nextNode);
		head->setPrev(nextNode);
	}

	numberOfNodes++;
};


void CycleList::deleteNode(Node * currentNode) {};