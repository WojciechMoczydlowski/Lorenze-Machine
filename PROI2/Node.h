#pragma once
class Node
{
public:
	Node();
	~Node();

	void setNext(Node * nextNode);
	void setPrev(Node * prev);
	void setValue(bool nodeValue);

	Node * getNext() { return next; }
	Node * getPrev() { return prev; }
	bool getValue() { return value; }

private:
	Node *next;
	Node *prev;
	bool value;
};

