#include "Queue2.h"

Queue2::Queue2()
{
	Queue::Queue();
}

void Queue2::SetHead(QueueElement* elem) 
{
	Queue::SetHead(elem);
}

QueueElement* Queue2::GetHead()
{
	return Queue::GetHead();
}

void Queue2::Push(int nmb)
{
	Queue::Push(nmb);
}

int Queue2::Pop()
{
	return Queue::Pop();
}

void Queue2::Print()
{
	Queue::Print();
}

Queue* Queue2::Copy()
{
	return Queue::Copy();
}

bool Queue2::Zero()
{
	return Queue::Zero();
}

int Queue2::Nmb()
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