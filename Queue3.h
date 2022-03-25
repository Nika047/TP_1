#include "Queue.h"

class Queue3 : protected Queue
{
public:
	Queue3();
	void Push(int elem);
	int Pop();
	void Print();
	bool Zero();
	QueueElement* GetHead();
	void SetHead(QueueElement* elem);
	Queue* Copy();
	int Nmb();

private:
};