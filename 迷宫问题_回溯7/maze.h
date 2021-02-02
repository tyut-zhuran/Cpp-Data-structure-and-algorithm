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
		//STL的出栈函数只是删除栈顶元素，而不返回，故重写
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

	//重写==
	bool operator== (const Cell& c) const
	{
		return (x == c.x) && (y == c.y);
	}

private:
	int x, y;
	//生命为friend可以使Maze中访问private
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
	//存放实时地图
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
	cout << "输入迷宫：\n" << "m - entry\n" 
		<< "e - exit\n" << "1 - wall\n" << "0 - passage\n" 
		<<"每次输入一行，ctrl+z结束。"<< endl;
	while (cin >> str)
	{
		//row从1开始
		row++;
		//获取列数
		cols = strlen(str);

		//左右两边用wall围住，留出\0的位置
		s = new char[cols + 3];

		mazeRows.push(s);
		strcpy_s(s+1, cols+1 ,str);
		s[0] = s[cols + 1] = wall;
		s[cols + 2] = '\0';

		//是否输入了出口
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

	//上下两边都用wall围住
	store = new char* [rows+2];


	//设置地图store
	store[0] = new char[cols + 3];

	for (; !mazeRows.empty(); row--)
	{
		//为store[1-row]填充输入的地图
		store[row] = mazeRows.pop();
	}
	store[rows + 1] = new char[cols+3];
	
	store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
	for (col = 0; col <= cols + 1; col++)
	{
		store[0][col] = wall;
		store[rows + 1][col] = wall;
	}
	//到此，初始化的地图已经构建完毕
}


void Maze::pushUnvisited(int row, int col)
{
	//回溯的核心所在，每到达一个新的位置后将可能的下一步压入栈中
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
		//输出当前的地图状态
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
			//栈空表示下一步无路可走
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

