#pragma once
# ifndef __GEN_ARRAY_QUEUE__
# define __GEN_ARRAY_QUEUE__

# include <iostream>
using namespace std;

//初始时first=last=-1
//第一个元素入队列后first=last=0
//不断入队后last递增


template<class T, int size=100>
class ArrayQueue {
public:
	ArrayQueue()
	{
		first = last = -1;
	}

	void enqueue(T);
	T dequeue();
	bool isFull()
	{
		return first == 0 && last == size - 1 || first == last + 1;
	}
	bool isEmpty()
	{
		return first == -1;
	}
	void printAll()
	{
		if (!isEmpty())
		{
			for (int i = first; i != last; i++)
			{
				cout << storage[i] << '\t';
				if (i == size - 1)
				{
					i = 0;
				}
			}
			cout << endl;
		}
		else
		{
			cout << "Empty Queue!" << endl;
		}
	}
private:
	int first, last;
	T storage[size];
};



template<class T, int size>
void ArrayQueue<T, size>::enqueue(T el)
{
	if (!isFull())
	{
		if (last == size - 1 || last == -1)
		{
			storage[0] = el;
			last = 0;
			if (first == -1)
			{
				first = 0;
			}
		}
		else storage[++last] = el;

		printAll();
	}
	else
		cout << "Full queue!!!" << endl;
}



template<class T, int size>
T ArrayQueue<T, size>::dequeue()
{
	if (!isEmpty())
	{
		T tmp;
		tmp = storage[first];
		if (first == last)
		{
			last = first = -1;
		}
		else if (first == size - 1)
		{
			first = 0;
		}
		else
			first++;

		printAll();
		return tmp;
	}
	else
	{
		cout << "Empty Queue" << endl;
		return 0;
	}
}




# endif