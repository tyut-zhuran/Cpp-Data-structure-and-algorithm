# include <iostream>
using namespace std;




//β�ݹ飬ֻ��һ���ݹ���ã���������֮��û���������Ҫִ��
void tail(int i)
{
	if (i > 0)
	{
		cout << i << ' ';
		tail(i-1);
	}

}


//β�ݹ������ת����ѭ������ʽ
void iterativeEquivalentTail(int i)
{
	for (; i > 0; i--)
	{
		cout << i << ' ';
	}

}



//��β�ݹ��һ�����ӣ����Խ����������෴��˳�����
//�ú���Ҫ���÷ǵݹ�ʵ�֣�����ʹ��һջ�ṹ������ʵ�֣����Ȼ�ȡһ�������������
//����������ĩβ��ʼ��ջ���
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



//쳲���������
//0 1 1 2 3 5 8 13 21����������
//�ݹ�ʵ��
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

//�ǵݹ�ʵ��
//˼·�����i-1��i-2��ֵ����Ҫ��ǰ������������
int iterativeFib(int i)
{
	//��ʼ��ָ�����е�ǰ����
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
