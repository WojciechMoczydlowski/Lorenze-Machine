#include "Node.h"
#pragma once
class CycleList
{
public:
	CycleList();
	~CycleList();

	Node* getHead() { return head; }

	void setHead(Node * headToSet);

	void addNode(bool value);
	void deleteNode(Node * currentNode);
private:
	Node* head;
};

