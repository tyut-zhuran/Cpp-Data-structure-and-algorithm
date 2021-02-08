#pragma once


# ifndef __GEN_BST__
# define __GEN_BST__

//二叉查找树
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
		//STL中的栈的pop()不会删除元素需要重写
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


	//深度优先遍历共有三个任务：V(访问节点)、L(访问左子树)、R(访问右子树)
	//若在规定L在R前面
	//则共有3中遍历方式：
	//前序遍历VLR
	void preorder() {
		preorder(root);
	}
	void iterativePreorder();


	//中序遍历LVR
	void inorder()
	{
		inorder(root);
	}

	//后序遍历LRV
	void postorder()
	{
		postorder(root);
	}
	void iterativePostorder();




	T* search(const T& el) const
	{
		return search(root, el);
	}

	//合并删除
	void deleteByMerging(BSTNode<T>*& node);
	void findAndDeleteByMerging(const T & el);


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

	//广度优先遍历
	void breadthFirst();
	virtual visit(BSTNode<T>* p)
	{
		cout << p->el >> ' ';
	}
};

//将el插入二叉查找树
template <class T>
void BST<T>::insert(const T& el)
{
	BSTNode<T>* p = root, * prev = 0;
	while (p != 0)
	{
		prev = p;
		if (el < p->el)
		{
			p = p->left;
		}
		else
			p = p->right;
	}
	//退出while后,prev指向的是要插入节点的父节点
	if (root == 0)
		root = new BSTNode<T>(el);
	else if (el < prev->el)
		prev->left = new BSTNode<T>(el);
	else
		prev->right = new BSTNode<T>(el);
}



//二叉查找树满足左小右大原则
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



//从上到下、从左到右广度优先遍历，使用队列
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

//非递归的前序遍历VLR
//利用栈数据结构来模拟递归时的运行时栈
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





//非递归的后序遍历
//一种实现方法是从前序遍历中修改：因为前序与后序的访问顺序正好相反，所以可以将前序中的
//visit()操作替换成入栈（再新建一个栈），而后在遍历完成后再依次出栈并调用visit（）

//这里使用另外一种方法
template<class T>
void BST<T>::iterativePostorder()
{
	Stack<BSTNode<T>*> travStack;
	BSTNode<T>* p = root, *q = root;
	while (p != 0)
	{
		//p指向正在遍历的树，于是先将其指向最深处
		for (; p->left != 0; p = p->left)
		{
			travStack.push(p);
		}

		//p始终指向正在遍历的树，而q始终刚刚遍历完成的树
		//若p->right == q，说明p的左右两边都已经访问过了
		while (p->right == 0 || p->right == q)
		{
			visit(p);
			q = p;
			if (travStack.empty())
				return;
			p = travStack.pop();
		}
		travStack.push(p);
		p = p->right;
	}
}







//合并删除，传入要删除节点的指针的引用（其父节点的元素left或right）
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node)
{

}

//传入要删除的元素
template<class T>
void BST<T>::findAndDeleteByMerging(const T& el)
{}

# endif












