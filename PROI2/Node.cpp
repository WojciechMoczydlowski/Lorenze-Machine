#include "pch.h"
#include "Node.h"
#include <iostream>

Node::Node()
{
	next = nullptr;
	prev = nullptr;
	value = true;
}

Node::~Node()
{
	next = nullptr;
	prev = nullptr;
}

void Node::setNext(Node * nextNode) { next = nextNode; }
void Node::setPrev(Node * prevNode) { prev = prevNode; }
void Node::setValue(bool nodeValue) { value = nodeValue;}
