#pragma once

# include <iostream>
# include <string>
# include <stack>

using namespace std;


template<class T>
class Stack : public stack<T> {
public:
	T pop()
	{
		//STL�ĳ�ջ����ֻ��ɾ��ջ��Ԫ�أ��������أ�����д
		T tmp = top();
		stack<T>::pop();
		return tmp;
}
};



class Cell {
public:
	Cell(int i = 0, int j = 0)
	{
		x = i;
		y = j;
	}

	//��д==
	bool operator== (const Cell& c) const
	{
		return (x == c.x) && (y == c.y);
	}

private:
	int x, y;
	//����Ϊfriend����ʹMaze�з���private
	friend class Maze;
};



class Maze {

public:
	Maze();
	void exitMaze();

private:
	Cell currentCell, exitCell, entryCell;
	const char exitMarker, entryMarker, visited, passage, wall;
	Stack<Cell> mazeStack;
	//���ʵʱ��ͼ
	char** store;

	void pushUnvisited(int, int);
	friend ostream& operator<< (ostream&, const Maze&);
	int rows, cols;
};

Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'), passage('0'),
wall('1') {
	
	Stack<char*> mazeRows;
	char str[80], * s;
	int col;
	int row = 0;
	cout << "�����Թ���\n" << "m - entry\n" 
		<< "e - exit\n" << "1 - wall\n" << "0 - passage\n" 
		<<"ÿ������һ�У�ctrl+z������"<< endl;
	while (cin >> str)
	{
		//row��1��ʼ
		row++;
		//��ȡ����
		cols = strlen(str);

		//����������wallΧס������\0��λ��
		s = new char[cols + 3];

		mazeRows.push(s);
		strcpy_s(s+1, cols+1 ,str);
		s[0] = s[cols + 1] = wall;
		s[cols + 2] = '\0';

		//�Ƿ������˳���
		if (strchr(s, exitMarker) != 0)
		{
			exitCell.x = row;
			exitCell.y = strchr(s, exitMarker) - s;
		}
		if (strchr(s, entryMarker) != 0)
		{
			entryCell.x = row;
			entryCell.y = strchr(s, entryMarker) - s;
		}
	}

	rows = row;

	//�������߶���wallΧס
	store = new char* [rows+2];


	//���õ�ͼstore
	store[0] = new char[cols + 3];

	for (; !mazeRows.empty(); row--)
	{
		//Ϊstore[1-row]�������ĵ�ͼ
		store[row] = mazeRows.pop();
	}
	store[rows + 1] = new char[cols+3];
	
	store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
	for (col = 0; col <= cols + 1; col++)
	{
		store[0][col] = wall;
		store[rows + 1][col] = wall;
	}
	//���ˣ���ʼ���ĵ�ͼ�Ѿ��������
}


void Maze::pushUnvisited(int row, int col)
{
	//���ݵĺ������ڣ�ÿ����һ���µ�λ�ú󽫿��ܵ���һ��ѹ��ջ��
	if (store[row][col] == passage || store[row][col] == exitMarker)
		mazeStack.push(Cell(row,col));
}


void Maze::exitMaze() {

	int row, col;
	currentCell = entryCell;
	while (!(currentCell == exitCell))
	{
		row = currentCell.x;
		col = currentCell.y;
		//�����ǰ�ĵ�ͼ״̬
		cout << *this;

		if (!(currentCell == entryCell))
		{
			store[row][col] = visited;
		}
		pushUnvisited(row-1,col);
		pushUnvisited(row+1,col);
		pushUnvisited(row,col-1);
		pushUnvisited(row,col+1);

		if (mazeStack.empty())
		{
			//ջ�ձ�ʾ��һ����·����
			cout << *this;
			cout << "failure!" << endl;
			return;
		}
		else
			currentCell = mazeStack.pop();
	}
	cout << *this;
	cout << "Success!" << endl;
}



ostream& operator<< (ostream& out, const Maze& maze)
{
	for (int row = 0; row <= maze.rows + 1; row++)
	{
		out << maze.store[row] << endl;
	}
	out << endl;
	return out;

}

