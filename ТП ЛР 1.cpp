#include <iostream>
#include <conio.h>
#include "Queue.h"
#include "Queue1.h"
#include "Queue2.h"
#include "Queue3.h"

using namespace std;

template <typename QueueSample>
QueueSample* Active;
Queue* buffer;
Queue1* queue1;
Queue2* queue2;
Queue3* queue3;

template <typename QueueSample>
void Unite(QueueSample *elem);
template <typename QueueSample>
void Command(int type, QueueSample elem);

int main()
{
	setlocale(LC_ALL, "Russian");

	queue1 = new Queue1();
	queue2 = new Queue2();
	queue3 = new Queue3();

	int QueueActive = 0;
	int type = 0;

	while (true)
	{
		cout << "Введите номер очереди (от 1 до 3): ";
		cin >> QueueActive;
		if (QueueActive > 0 && QueueActive < 4) break;
	}

	while (true)
	{
		cout << "\nСписок возможных действий: \n";
		cout << "1. Добавить элемент \n";
		cout << "2. Извлечь элемент \n";
		cout << "3. Слияние \n";
		cout << "4. Скопировать очередь \n";
		cout << "5. Выполнение расчета по варианту \n";
		cout << "6. Вывод очереди \n";
		cout << "7. Выход \n\n";
		cout << "Выберите номер команды: ";
		cin >> type;

		switch (QueueActive)
		{
		case 1:
			Active<Queue1> = queue1;
			Command(type, Active<Queue1>);
			break;

		case 2:
			Active<Queue2> = queue2;
			Command(type, Active<Queue2>);
			break;

		case 3:
			Active<Queue3> = queue3;
			Command(type, Active<Queue3>);
			break;
		}
		system("cls");
	}
}

template <typename QueueSample>
void Command(int type, QueueSample elem)
{
	switch (type)
	{
	case 1:
		int n;
		cout << "Введите число: ";
		cin >> n;
		elem->Push(n);

		cout << "Добавлено \n\n";
		cout << "Нажмите ENTER \n";
		break;

	case 2:
		if (elem->Zero())
			cout << "Нет элементов \n";
		else
			cout << "Результат: " << elem->Pop();

		cout << "\n\nНажмите ENTER \n";
		_getch();
		break;

	case 3:
		Unite(elem);
		cout << "Вставлено \n\n";
		cout << "Нажмите ENTER \n";
		_getch();
		break;

	case 4:
		if (elem->Zero())
		{
			cout << "Нет элементов\n\n";
			break;
		}
		buffer = elem->Copy();
		cout << "Скопировано \n\n";
		cout << "Нажмите ENTER \n";
		_getch();
		break;

	case 5:
		if (elem->Zero())
			cout << "Нет элементов \n";
		else
			cout << "Количество четных элементов, больших среднего арифметического: " << elem->Nmb();

		cout << "\n\nНажмите ENTER \n";
		_getch();
		break;

	case 6:
		if (elem->Zero())
			cout << "Нет элементов ";
		else
			elem->Print();

		cout << "\n\nНажмите ENTER \n";
		_getch();
		break;

	case 7:
		exit(0);
		break;
	}
}

template <typename QueueSample>
void Unite(QueueSample *elem)
{
	QueueElement *current = buffer->GetHead();

	while (current->GetPrev())
		current = current->GetPrev();

	current->SetPrev(elem->GetHead());
	elem->SetHead(buffer->GetHead());
	buffer = nullptr;
}