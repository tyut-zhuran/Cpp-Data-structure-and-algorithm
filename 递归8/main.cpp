# include <iostream>
using namespace std;




//尾递归，只有一个递归调用，并且在其之后没有其他语句要执行
void tail(int i)
{
	if (i > 0)
	{
		cout << i << ' ';
		tail(i-1);
	}

}


//尾递归很容易转换成循环的形式
void iterativeEquivalentTail(int i)
{
	for (; i > 0; i--)
	{
		cout << i << ' ';
	}

}



//非尾递归的一个例子，可以将输入行以相反的顺序输出
//该函数要想用非递归实现，可以使用一栈结构（数组实现），先获取一行输入放入数组
//而后从数组的末尾开始出栈输出
void reverse()
{
	char ch;
	cin.get(ch);
	if (ch != '\n')
	{
		reverse();
		cout.put(ch);
	}
}



//斐波那契数列
//0 1 1 2 3 5 8 13 21·····
//递归实现
int Fib(int i)
{
	if (i < 2)
	{
		return i;
	}
	else
	{
		return Fib(i - 1) + Fib(i - 2);
	}
}

//非递归实现
//思路是求出i-1和i-2的值（需要把前面所有项都求出）
int iterativeFib(int i)
{
	//初始化指向数列的前两项
	int current = 1, last = 0;
	int tmp;
	for (int j = 0; j < i-1 ; j++)
	{
		tmp = current;
		current += last;
		last = tmp;
	}
	return current;
}

int main()
{

	tail(10);
	cout << endl;
	iterativeEquivalentTail(10);
	cout << endl;

	reverse();
	cout << endl;

	cout << Fib(10) << endl;
	cout << endl;
	
	cout << iterativeFib(10) << endl;
	cout << endl;
	return 0;
}
