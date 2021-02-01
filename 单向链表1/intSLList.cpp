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
	
	//考虑链表为空时的情况
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
	//同样需考虑链表为空的情况
	else
	{
		head = tail = temp;
	}
}



//实际上考虑不够周全，还应该考虑链表为空的情况
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

//实际上考虑不够周全，还应该考虑链表为空的情况
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
		//最麻烦，要找的Node不在第一个
		else
		{
			IntSLLNode* pred, * temp;
			for (pred = head, temp = head->next;
				(temp->info != el) && (temp != 0);
				pred = pred->next, temp = temp->next);
			if (temp != 0)
			{
				//找到Node
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

