# include "intSLList.h"



int main()
{
	IntSLList* list = new IntSLList();
	list->addToHead(1);
	list->addToHead(2);
	list->addToHead(3);
	list->addToHead(4);
	list->addToHead(5);
	list->addToHead(6);
	list->addToTail(100);
	list->addToTail(99);
	list->addToTail(98);
	list->addToTail(97);
	list->addToTail(96);
	list->addToTail(95);
	list->addToTail(94);


	list->deleteFromHead();
	list->deleteFromTail();

	list->deleteNode(99);

	list->printAllNode();

	return 0;
}





