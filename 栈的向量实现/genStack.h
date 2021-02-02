#pragma once
//general class for vector implementation of stack

# ifndef STACK
# define STACK

# include <iostream>
using namespace std;
# include <vector>

template<class T, int capacity = 30>
class Stack {

public:
	Stack()
	{
		pool.reserve(capacity);
	}

	void clear()
	{
		pool.clear();
	}

	bool isEmpty() const
	{
		return pool.empty();
	}

	T& topEl()
	{
		return pool.back();
	}


	T pop()
	{
		T el = pool.back();
		pool.pop_back();
		return el;
	}

	void push(const T& el)
	{
		pool.push_back(el);
	}


	void printAll()
	{
		for(vector<T>::iterator it = pool.begin(); it != pool.end(); it++)
		{
			cout << *it << '\t';
		}
		cout << endl;
	}

private:
	vector<T> pool;
};

# endif



