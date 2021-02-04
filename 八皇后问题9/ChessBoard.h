#pragma once

# ifndef __CHESS_BOARD__
# define __CHESS_BOARD__

# include <iostream>
using namespace std;


class ChessBoard {
public:

	ChessBoard();//8*8
	ChessBoard(int);//n*n
	void findSolutions();

private:
	const bool available;
	const int squares, norm;
	bool* column, * leftDiagonal, * rightDiagonal;
	int* positionInRow, howMany;
	void putQueen(int row);
	void printBoard(ostream&);
	void initializeBoard();
};



ChessBoard::ChessBoard() :available(true), squares(8), norm(squares - 1)
{
	initializeBoard();
}
ChessBoard::ChessBoard(int n) :available(true), squares(n), norm(squares-1)
{
	initializeBoard();
}

void ChessBoard::initializeBoard()
{
	register int i;
	column = new bool[squares];
	positionInRow = new int[squares];
	leftDiagonal = new bool[squares*2-1];
	rightDiagonal = new bool[squares*2-1];
	for (i = 0; i < squares; i++)
	{
		positionInRow[i] = -1;
	}
	for (i = 0; i < squares; i++)
	{
		column[i] = -1;
	}
	for (i = 0; i < squares * 2 - 1; i++)
	{
		leftDiagonal[i] = rightDiagonal[i] = available;
	}
	howMany = 0;
}


void ChessBoard::putQueen(int row)
{
	for (int col = 0; col < squares; col++)
	{
		//��⵱ǰλ���Ƿ����
		if (column[col] == available &&
			leftDiagonal[row + col] == available &&
			rightDiagonal[row + (norm - col)] == available)
		{
			//�洢��row�еĻʺ������һ��
			positionInRow[row] = col;

			//����һ���ʺ�֮������ͬ��ͬб�ߵ�λ�ö�������
			column[col] = !available;
			leftDiagonal[row + col] = !available;
			rightDiagonal[row + (norm - col)] = !available;

			if (row < squares - 1)
			{
				putQueen(row + 1);
			}
			else
			{
				//�ɹ�
				howMany++;
				printBoard(cout);
			}

			//��������̽���
			column[col] = available;
			leftDiagonal[row + col] = available;
			rightDiagonal[row + (norm - col)] = available;

		}
	}
}


void ChessBoard::printBoard(ostream& out)
{
	char ch;
	for (register int row = 0; row < squares; row++)
	{
		for (register int col = 0; col < squares; col++)
		{
			ch = (positionInRow[row] == col) ? '*' : '.';
			out << ch;
		}
		out << endl;
	}
	out << endl << endl;
}


void ChessBoard::findSolutions()
{
	initializeBoard();
	putQueen(0);
	cout << howMany << " solutions found.\n";
}



# endif
