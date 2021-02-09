# include "genBST.h"



int main()
{
	BST<int>* tree = new BST<int>();

	tree->insert(5);
	tree->insert(6);
	tree->insert(3);
	tree->insert(2);
	tree->insert(1);
	tree->insert(5);
	tree->insert(7);
	tree->insert(8);
	tree->insert(3);
	tree->insert(9);
	tree->insert(5);
	tree->insert(10);
	tree->insert(2);
	tree->insert(78);
	tree->insert(3);

	tree->preorder();
	cout << endl;

	tree->inorder();
	cout << endl;

	tree->postorder();
	cout << endl;

	tree->iterativePreorder();
	cout << endl;
	
	tree->iterativePostorder();
	cout << endl;
	
	tree->findAndDeleteByCopying(10);
	cout << endl;
	
	tree->findAndDeleteByMerging(8);
	cout << endl;

	tree->preorder();
	cout << endl;
	tree->inorder();
	cout << endl;
	tree->postorder();
	cout << endl;
	tree->breadthFirst();
	cout << endl;
	return 0;
}


