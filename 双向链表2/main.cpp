# include "genDLList.h"


int main()
{
	DoublyLinkedList<double>* list = new DoublyLinkedList<double>;


	list->addToDLLTail(0.03);
	list->addToDLLTail(0.05);
	list->addToDLLTail(0.07);
	list->addToDLLTail(0.09);
	list->deleteFromDLLTail();

	list->printAllNode();

	return 0;
}


