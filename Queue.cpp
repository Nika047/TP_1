#include <iostream>
#include "Queue.h"

Queue::Queue() {};

Queue* Queue::Copy()
{
	Queue *NewQueue = new Queue;
	NewQueue->head = new QueueElement(*this->head);
	QueueElement *current = NewQueue->head;

	while (current)
	{
		QueueElement *prev = current->GetPrev();
		if (prev) 
		{
			QueueElement *tmp = new QueueElement(*prev);
			current->SetPrev(tmp);
			current = tmp;
		} 
		else
			break;
	}
	std::cout << "Скопировано \n";
	return NewQueue;
}

void Queue::SetHead(QueueElement* elem)
{
	this->head = elem;
}

void Queue::Push(int elem)
{
	QueueElement *element = new QueueElement(elem, head);
	this->head = element;
}

int Queue::Pop()
{
	if (Zero()) 
		return -1;

	QueueElement *last = this->head;
	QueueElement *prev = last;

	while (last)
	{
		if (last->GetPrev()) 
		{
			prev = last;
			last = last->GetPrev();
		}
		else
			break;
	}
	int val = last->GetData();
	prev->SetPrev(nullptr);
	delete last;
	return val;
}

QueueElement* Queue::GetHead()
{
	return head;
}

void Queue::Print()
{
	QueueElement *current = this->head;
	while (current)
	{
		std::cout << current->GetData();
		current = current->GetPrev();
		if (current)
			std::cout << " || ";
	}
	std::cout << std::endl;
}

bool Queue::Zero()
{
	return this->head == nullptr;
}