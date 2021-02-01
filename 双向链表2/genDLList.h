#pragma once
# ifndef __GENDLLIST_H__
# define __GENDLLIST_H__

# include <iostream>
using namespace std;


//gen = general





template<class T>
class DLLNode {
public:
	DLLNode() {
		next = prev = 0;
	}

	DLLNode(const T& el, DLLNode* n = 0, DLLNode* p = 0)
	{
		info = el;
		next = n;
		prev = p;
	}
	T info;
	DLLNode* next, * prev;
};

template<class T>
class DoublyLinkedList {
public:
	DoublyLinkedList()
	{
		head = tail = 0;
	}
	
	void addToDLLTail(const T&);
	T deleteFromDLLTail();
	void printAllNode();

protected:
	DLLNode<T>* head, * tail;
};














template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el)
{
	if (tail != 0)
	{
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else
	{
		//该构造函数默认next=prev=0
		head = tail = new DLLNode<T>(el);
	}
}



//不够严谨，还应该考虑链表为空的场景(try catch)
template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	if (head != 0)
	{
		T el = tail->info;
		if (head == tail)
		{
			delete head;
			head = tail = 0;
		}

		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = 0;
		}
		return el;
	}
	return 0;
}



template<class T>
void DoublyLinkedList<T>::printAllNode()
{
	DLLNode<T>* temp = head;
	for (; temp != 0; temp = temp->next)
	{
		cout << temp->info << '\t';
	}
	cout << endl;

	for (temp = tail; temp != head; temp = temp->prev)
	{
		cout << temp->info << '\t';
	}
	cout << temp->info << '\t' << endl;
}

# endif



