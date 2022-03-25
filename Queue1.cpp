#include "Queue1.h"

int Queue1::Nmb()
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