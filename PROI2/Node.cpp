#include "pch.h"
#include "Node.h"


Node::Node()
{
	next = nullptr;
	prev = nullptr;
}

Node::~Node()
{
	next = nullptr;
	prev = nullptr;
}

void Node::setNext(Node * nextNode) { next = nextNode; }
void Node::setPrev(Node * prevNode) { prev = prevNode; }
void Node::setValue(bool nodeValue) { value = nodeValue; }
