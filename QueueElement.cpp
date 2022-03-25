#include "QueueElement.h"

QueueElement::QueueElement(int data, QueueElement *prev) 
{
	this->data = data;
	this->prev = prev;
}

QueueElement::QueueElement(const QueueElement &elem) 
{
	this->data = elem.data;
	this->prev = elem.prev;
}

QueueElement::~QueueElement() 
{
	this->data = 0;
	this->prev = nullptr;
}

int QueueElement::GetData() 
{
	return data;
}

QueueElement* QueueElement::GetPrev() 
{
	return prev;
}

void QueueElement::SetPrev(QueueElement* prev) 
{
	this->prev = prev;
}