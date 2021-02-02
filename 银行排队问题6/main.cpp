
# include "genQueue.h"

# include <iostream>
using namespace std;
/*
����������
��֪������ÿ���ӵ����˿������ķֲ��Լ�ÿ���˿���Ҫ����ʱ��ķֲ�
ϣ���ҵ����ʵĹ�Ա��
*/

int option(int percents[])
{
	register int i = 0, choice = rand() % 100 + 1, perc;
	for (perc = percents[0]; perc < choice; i++, perc += percents[i]);
	return i;
}

int main()
{
	//ÿ���ӵ����Ĺ˿���Ϊ0,1,2,3,4�ĸ���
	int arrivals[] = {15,20,25,10,30};

	//��Ҫ����30��ĸ���Ϊ10%��40��Ϊ5%���Դ�����
	int service[] = {0,0,0,10,5,10,10,0,15,25,10,15};


	//ÿ����Աǰ�Ŷӵ�ʱ��
	int clerks[] = {0,0,0,0,0};
	int numOfClerks = sizeof(clerks) / sizeof(int);
	
	int customers;
	int t;
	int i;
	int numOfMinutes = 100;
	int x;

	//100���������ڵȴ��Ĺ˿��������ʱ������ֵ
	double maxWait = 0;
	//��ǰ�ȴ��Ĺ˿�����ʱ���
	double currWait = 0;
	//100�������й˿͵ȴ��ķ�����
	double thereIsLine = 0;


	Queue<int> simuQ;

	//���double�ľ��ȣ���λС����
	cout.precision(2);

	for (t = 1; t < numOfMinutes; t++)
	{
		cout << "t = " << t;
		
		//�÷����ڸ�����Ա�ѱ������ߵ�ʱ��
		for (i = 0; i < numOfClerks; i++)
		{
			if (clerks[i] < 60)
				clerks[i] = 0;
			else
				clerks[i] -= 60;
		}

		//ѡ����t���ӵ��������
		customers = option(arrivals);


		//ѡ��ÿλ�˿���Ҫ�ķ���ʱ�䲢�������
		for (i = 0; i < customers; i++)
		{
			x = option(service) * 10;
			simuQ.enqueue(x);
			currWait += x;
		}


		//Ϊÿ����Ա������Ҫ����Ĺ˿�
		for (i = 0; i < numOfClerks && !simuQ.isEmpty();)
		{
			if (clerks[i] < 60)
			{
				x = simuQ.dequeue();
				clerks[i] += x;
				currWait -= x;
			}
			else i++;
		}


		if (!simuQ.isEmpty())
		{
			thereIsLine++;
			cout << " currWait=" << currWait / 60.0 << endl;
			if (maxWait < currWait)
				maxWait = currWait;
		}
		else
			cout << " currWait = 0;" << endl;
	}
	cout << "\nFor " << numOfClerks << " clerks, there was a line "
		<< thereIsLine / numOfMinutes * 100 << "% of the time;\n"
		<< "maximum wait time was " << maxWait / 60.0 << " min.";
	return 0;
}






