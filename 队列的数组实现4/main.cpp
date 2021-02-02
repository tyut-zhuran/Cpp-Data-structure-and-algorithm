# include "genArrayQueue.h"


int main()
{
	ArrayQueue<int, 30>* queue = new ArrayQueue<int, 30>;

	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);
	queue->enqueue(4);
	queue->dequeue();
	queue->dequeue();
	queue->enqueue(5);
	queue->enqueue(6);
	queue->dequeue();
	queue->enqueue(7);
	queue->enqueue(8);
	queue->enqueue(9);
	queue->dequeue();
	queue->dequeue();

	queue->enqueue(1);
	return 0;
}




