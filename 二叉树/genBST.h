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
		T tmp = stack<T>::top();
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
		T tmp = queue<T> ::front();
		queue<T>::pop();
		return tmp;
	}

	void enqueue(const T& el)
	{
		queue<T>::push(el);
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
	void iterativePostorder();




	T* search(const T& el) const
	{
		return search(root, el);
	}

	//�ϲ�ɾ��
	void deleteByMerging(BSTNode<T>*& node);
	void findAndDeleteByMerging(const T & el);

	//����ɾ��
	void deleteByCopying(BSTNode<T>*& node);
	void findAndDeleteByCopying(const T& el);

	//������ȱ���
	void breadthFirst();







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


	virtual void visit(BSTNode<T>* p)
	{
		cout << p->el << ' ';
	}
};

//��el������������
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
	//�˳�while��,prevָ�����Ҫ����ڵ�ĸ��ڵ�
	if (root == 0)
		root = new BSTNode<T>(el);
	else if (el < prev->el)
		prev->left = new BSTNode<T>(el);
	else
		prev->right = new BSTNode<T>(el);
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
//����ջ���ݽṹ��ģ��ݹ�ʱ������ʱջ
template<class T>
void BST<T>::iterativePreorder()
{
	Stack<BSTNode<T>*> travStack;
	BSTNode<T>* p = root;
	cout << endl;
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





//�ǵݹ�ĺ������
//һ��ʵ�ַ����Ǵ�ǰ��������޸ģ���Ϊǰ�������ķ���˳�������෴�����Կ��Խ�ǰ���е�
//visit()�����滻����ջ�����½�һ��ջ���������ڱ�����ɺ������γ�ջ������visit����

//����ʹ������һ�ַ���
template<class T>
void BST<T>::iterativePostorder()
{
	Stack<BSTNode<T>*> travStack;
	BSTNode<T>* p = root, *q = root;
	cout << endl;
	while (p != 0)
	{
		//pָ�����ڱ��������������Ƚ���ָ�����
		for (; p->left != 0; p = p->left)
		{
			travStack.push(p);
		}

		//pʼ��ָ�����ڱ�����������qʼ�ոոձ�����ɵ���
		//��p->right == q��˵��p���������߶��Ѿ����ʹ���
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







//�ϲ�ɾ��������Ҫɾ���ڵ��ָ������ã��丸�ڵ��Ԫ��left��right��
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node)
{
	BSTNode<T>* tmp = node;

	//��Ҫɾ���Ľڵ�û����ڵ㣬��ֱ�ӽ�nodeָ���ҽڵ㼴��
	if (node->left == 0)
	{
		node = node->right;
	}
	//û���ҽڵ�ͬ��
	else if (node->right == 0)
	{
		node = node->left;
	}
	else
	{
		//�ҵ�node�������е����ֵ������node����������������
		tmp = node->left;
		while (tmp->right != 0)
			tmp = tmp->right;
		//�˳�while��tmpָ��node�������е����ֵ�ڵ�
		
		tmp->right = node->right;
		
		tmp = node;
		node = node->left;
	}
	delete tmp;
}

//����Ҫɾ����Ԫ��
template<class T>
void BST<T>::findAndDeleteByMerging(const T& el)
{
	BSTNode<T>* node = root, * prev = 0;
	while (node != 0)
	{
		if (node->el == el)
			break;
		prev = node;
		if (el < node->el)
			node = node->left;
		else
			node = node->right;
	}
	
	//���˳�whileʱnode��Ϊ0��˵���ҵ�����Ӧ�ڵ㣬��nodeָ��ľ���Ҫɾ���Ľڵ㣬prevָ���丸�ڵ�
	if (node != 0 && node->el == el)
	{
		if (node == root)
		{
			deleteByMerging(root);
		}
		else if (prev->left == node)
		{
			//ע��ú�������Ϊ���� 
			deleteByMerging(prev->left);
		}
		else
			deleteByMerging(prev->right);
	}
	else if (root != 0)
		cout << "el = " << el << "is not in the tree\n";
	else
		cout << "the tree is empty!\n";
}



template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node)
{
	BSTNode<T>* tmp = node, * prev;
	if (node->right == 0)
		node = node->left;
	else if (node->left == 0)
		node = node->right;
	else
	{
		//��������������������
		tmp = node->left;
		prev = node;
		while (tmp->right != 0)
		{
			prev = tmp;
			tmp = tmp->right;
		}
		//�˳�while��tmpָ��������ֵ�ڵ㣬prevָ��������ֵ�ĸ��ڵ�
		node->el = tmp->el;

		//node��������û��������
		if (prev == node)
			prev->left = tmp->left;
		else
			prev->right = tmp->right;
	}
	delete tmp;
}

template<class T>
void BST<T>::findAndDeleteByCopying(const T& el)
{
	BSTNode<T>* node = root, * prev = 0;
	while (node != 0)
	{
		if (node->el == el)
			break;
		prev = node;
		if (el < node->el)
			node = node->left;
		else
			node = node->right;
	}

	//���˳�whileʱnode��Ϊ0��˵���ҵ�����Ӧ�ڵ㣬��nodeָ��ľ���Ҫɾ���Ľڵ㣬prevָ���丸�ڵ�
	if (node != 0 && node->el == el)
	{
		if (node == root)
		{
			deleteByCopying(root);
		}
		else if (prev->left == node)
		{
			//ע��ú�������Ϊ���� 
			deleteByCopying(prev->left);
		}
		else
			deleteByCopying(prev->right);
	}
	else if (root != 0)
		cout << "el = " << el << "is not in the tree\n";
	else
		cout << "the tree is empty!\n";
}



# endif












