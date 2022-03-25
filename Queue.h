#include "QueueElement.h"
#pragma once

class Queue 
{
public:
	Queue();
	void Push(int element);
	int Pop();
	void Print();
	bool Zero();
	QueueElement* GetHead();
	void SetHead(QueueElement* elem);
	Queue* Copy();
	int Nmb();

private:
	QueueElement *head;
};


