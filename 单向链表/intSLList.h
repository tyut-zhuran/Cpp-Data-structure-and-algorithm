# ifndef __INTSLLIST_H__
# define __INTSLLIST_H__

class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}

	
	IntSLLNode(int el, IntSLLNode* ptr = 0) {
		info = el;
		next = ptr;
	}

	int info;
	IntSLListNode* next;
};


class IntSLList {
public:
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();


	int isEmpty()
	{
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();

	//detete node that with a info==int para
	void deleteNode(int);
	bool isInList(int) const;

private:
	IntSLListNode* head;
	IntSLListNode* tail;
};


# endif