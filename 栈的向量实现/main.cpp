# include "genStack.h"


int main()
{
	Stack<int>* stack = new Stack<int>;
	stack->push(20);
	stack->push(30);
	stack->push(30);
	stack->push(30);
	stack->push(30);
	stack->push(50);
	stack->push(50); 
	stack->push(50);

	stack->printAll();

	stack->pop();
	stack->pop();
	stack->printAll();

	stack->clear();
	stack->printAll();

	return 0;
}



