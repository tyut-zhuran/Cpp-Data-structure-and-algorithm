#pragma once


# ifndef __GEN_BST__
# define __GEN_BST__

//���������
//generic binary search tree

# include <queue>
# include <stack>
# include <iostream>
using namespace std;


template <class T>
class Stack :public stack<T>
{
public:
	T pop()
	{
		//STL�е�ջ��pop()����ɾ��Ԫ����Ҫ��д
		T tmp = top();
		stack<T>::pop();
		return tmp;
	}
};


template <class T>
class Queue : public queue<T>
{
public:
	T dequeue()
	{
		T tmp = front();
		queue<T>::pop();
		return tmp;
	}

	void enqueue(const T& el)
	{
		push(el);
	}
};

template<class T>
class BSTNode {
public:
	BSTNode()
	{
		left = right = 0;
	}

	BSTNode(const T& e, BSTNode<T>* l = 0, BSTNode<T>* r = 0)
	{
		el = e;
		left = l;
		right = r;
	}

	T el;
	BSTNode<T>* left, *right;

};

template <class T>
class BST {
public:
	BST()
	{
		root = 0;
	}

	~BST()
	{
		clear();
	}
	void clear()
	{
		clear(root);
		root = 0;
	}


	bool isEmpty() const {
		return root == 0;
	}

	void insert(const T&);


	//������ȱ���������������V(���ʽڵ�)��L(����������)��R(����������)
	//���ڹ涨L��Rǰ��
	//����3�б�����ʽ��
	//ǰ�����VLR
	void preorder() {
		preorder(root);
	}
	void iterativePreorder();


	//�������LVR
	void inorder()
	{
		inorder(root);
	}

	//�������LRV
	void postorder()
	{
		postorder(root);
	}

	T* search(const T& el) const
	{
		return search(root, el);
	}

protected:
	BSTNode<T>* root;
	void clear(BSTNode<T>*);
	T* search(BSTNode<T>*, const T&) const;
	
	//VLR
	void preorder(BSTNode<T>*);
	//LVR
	void inorder(BSTNode<T>*);
	//LRV
	void postorder(BSTNode<T>*);

	//������ȱ���
	void breadthFirst();
	virtual visit(BSTNode<T>* p)
	{
		cout << p->el >> ' ';
	}
};

template <class T>
void BST<T>::insert(const T& el)
{
}



//���������������С�Ҵ�ԭ��
template <class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const
{
	while (p != 0)
	{
		if (el == p->el)
			return &p->el;
		else if (el < p->el)
			p = p->left;
		else
			p = p->right;
	}
	return 0;
}



//���ϵ��¡������ҹ�����ȱ�����ʹ�ö���
template <class T>
void BST<T>::breadthFirst()
{
	Queue<BSTNode<T>*> queue;
	BSTNode<T>* p = root;
	if (p != 0)
	{
		queue.enqueue(p);
		while (!queue.empty())
		{
			p = queue.dequeue();
			visit(p);
			if (p->left != 0)
				queue.enqueue(p->left);
			if (p->right != 0)
				queue.enqueue(p->right);
		}
	}
}

template<class T>
void BST<T>::preorder(BSTNode<T>* p)
{
	if (p != 0)
	{
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}

template<class T>
void BST<T>::inorder(BSTNode<T>* p)
{
	if (p != 0)
	{
		preorder(p->left);
		visit(p);
		preorder(p->right);
	}
}

template<class T>
void BST<T>::postorder(BSTNode<T>* p)
{
	if (p != 0)
	{
		preorder(p->left);
		preorder(p->right);
		visit(p);
	}
}

//�ǵݹ��ǰ�����VLR
template<class T>
void BST<T>::iterativePreorder()
{
	Stack<BSTNode*> travStack;
	BSTNode<T>* p = root;
	if (p != 0)
	{
		travStack.push(p);
		while (!travStack.empty())
		{
			p = travStack.pop();
			visit(p);
			if (p->right != 0)
			{
				travStack.push(p->right);
			}
			if (p->left != 0)
			{
				travStack.push(p->left);
			}
		}
	}
}


# endif












