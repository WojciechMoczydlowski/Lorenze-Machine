#pragma once
class Node
{
public:
	Node();
	~Node();

	void setNext(Node * nextNode);
	void setPrev(Node * prev);
	void setValue(int nodeValue);

	Node * getNext() { return next; }
	Node * getPrev() { return prev; }
	int getValue() { return value; }

private:
	Node *next;
	Node *prev;
	int value;
};

