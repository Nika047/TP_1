class QueueElement
{
public:
	QueueElement(int data, QueueElement *prev);
	QueueElement(const QueueElement &QueueElement);
	~QueueElement();
	int GetData();
	QueueElement* GetPrev();
	void SetPrev(QueueElement* prev);

private:
	int data;
	QueueElement *prev;
};