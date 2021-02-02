#pragma once
# ifndef __GEN_QUEUE__
# define __GEN_QUEUE__

# include <list>
# include <iostream>
using namespace std;

template <class T>
class Queue {
public:
	Queue()
	{}

	void clear()
	{
		lst.clear();
	}

	bool isEmpty()
	{
		return lst.empty();
	}

	T& front()
	{
		return lst.front();
	}


	T dequeue()
	{
		T el = lst.front();
		lst.pop_front();
		printAll();
		return el;
	}


	void enqueue(const T& el)
	{
		lst.push_back(el);
		printAll();
	}

	void printAll()
	{
		if (!isEmpty())
		{
			for (list<T>::iterator it = lst.begin(); it != lst.end(); it++)
			{
				cout << *it << '\t';
			}
			cout << endl;
		}
		else
			cout << "Empty Queue!" << endl;
	}
private:
	list<T> lst;
};



#endif  __GEN_QUEUE__
