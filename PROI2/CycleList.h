#include "Node.h"
#pragma once
class CycleList
{
public:
	CycleList();
	~CycleList();

	int getNumberOfNode() { return numberOfNodes; }
	Node* getHead() { return head; }

	void setNumberOfNodes(int numberOfNodesToSet);
	void setHead(Node * headToSet);

	void addNode(bool value);
	void deleteNode(Node * currentNode);
private:
	int numberOfNodes;
	Node* head;

};

