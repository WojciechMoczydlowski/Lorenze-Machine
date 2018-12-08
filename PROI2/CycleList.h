#pragma once
class CycleList
{
public:
	CycleList();
	~CycleList();
protected: 
	int numberOfNode;
	CycleList *next;
	CycleList *prev;

	void addNode(bool value);
	void deleteNode(bool value);

};

