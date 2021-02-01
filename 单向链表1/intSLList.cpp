# include <iostream>
using namespace std;
# include "intSLList.h"


IntSLList:: ~IntSLList() {
	for (IntSLLNode* p; !isEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
}


void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el, head);
	
	//��������Ϊ��ʱ�����
	if (tail == 0)
	{
		tail = head;
	}
}



void IntSLList::addToTail(int el)
{
	IntSLLNode* temp = new IntSLLNode(el);
	if (tail != 0)
	{
		tail->next = temp;
		tail = temp;
	}
	//ͬ���迼������Ϊ�յ����
	else
	{
		head = tail = temp;
	}
}



//ʵ���Ͽ��ǲ�����ȫ����Ӧ�ÿ�������Ϊ�յ����
int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode* temp = head;
	if (head == tail)
		head = tail = 0;
	else
		head = head->next;
	delete temp;
	return el;
}

//ʵ���Ͽ��ǲ�����ȫ����Ӧ�ÿ�������Ϊ�յ����
int IntSLList::deleteFromTail()
{
	int el = tail->info;
	if (head == tail)
	{
		delete tail;
		head = tail = 0;
	}
	else
	{
		IntSLLNode* temp = head;
		for (; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}
	return el;
}


void IntSLList::deleteNode(int el)
{
	if (head != 0)
	{
		if (head == tail && el == head->info)
		{
			delete head;
			head = tail = 0;
		}
		else if (el == head->info)
		{
			IntSLLNode* temp = head->next;
			delete head;
			head = temp;
		}
		//���鷳��Ҫ�ҵ�Node���ڵ�һ��
		else
		{
			IntSLLNode* pred, * temp;
			for (pred = head, temp = head->next;
				(temp->info != el) && (temp != 0);
				pred = pred->next, temp = temp->next);
			if (temp != 0)
			{
				//�ҵ�Node
				pred->next = temp->next;
				if (temp == tail)
				{
					tail == pred;
				}
				delete temp;
			}
		}
	}
}

bool IntSLList::isInList(int el) const
{
	IntSLLNode* temp;
	for (temp = head; (temp->info != el) && (temp != 0); temp = temp->next);
	return temp != 0;
}


bool IntSLList::isEmpty()
{
	return head == 0;
}


void IntSLList::printAllNode()
{
	for (IntSLLNode* temp = head; temp != 0; temp = temp->next)
	{
		cout << temp->info << '\t';
	}
	cout << '\t' << endl;
}

