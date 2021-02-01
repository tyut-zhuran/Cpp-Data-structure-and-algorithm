#pragma once
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
	IntSLLNode* next;
};


class IntSLList {
public:
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();


	bool isEmpty();
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();

	//删掉info为特定值的第一个节点
	void deleteNode(int);
	bool isInList(int) const;


	void printAllNode();

private:
	IntSLLNode* head;
	IntSLLNode* tail;
};


# endif