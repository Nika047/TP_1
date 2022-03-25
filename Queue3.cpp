#include "Queue3.h"

Queue3::Queue3()
{
	Queue::Queue();
}

QueueElement* Queue3::GetHead() 
{
	return Queue::GetHead();
}

void Queue3::SetHead(QueueElement* elem) 
{
	Queue::SetHead(elem);
}

void Queue3::Push(int elem) 
{
	Queue::Push(elem);
}

int Queue3::Pop() 
{
	return Queue::Pop();
}

void Queue3::Print() 
{
	Queue::Print();
}

Queue* Queue3::Copy()
{
	return Queue::Copy();
}

bool Queue3::Zero()
{
	return Queue::Zero();
}

int Queue3::Nmb()
{
	QueueElement* actual = this->GetHead();
	int cnt = 0;
	float aver = 0.0;
	float s = 0.0;
	int nmb = 0;

	while (actual)
	{
		cnt++;
		s += actual->GetData();
		actual = actual->GetPrev();
	}
	aver = s / cnt;
	actual = this->GetHead();

	while (actual)
	{
		if ((float)actual->GetData() > aver && actual->GetData() % 2 == 0)
			nmb++;
		actual = actual->GetPrev();
	}
	return nmb;
}