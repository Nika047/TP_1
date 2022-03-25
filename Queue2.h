#include "Queue.h"

class Queue2 : private Queue
{
public:
	Queue2();
	void Push(int element);
	int Pop();
	void Print();
	bool Zero();
	QueueElement* GetHead();
	void SetHead(QueueElement* elem);
	Queue* Copy();
	int Nmb();

private:
};