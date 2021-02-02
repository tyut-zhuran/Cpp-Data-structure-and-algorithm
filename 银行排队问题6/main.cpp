
# include "genQueue.h"

# include <iostream>
using namespace std;
/*
问题描述：
已知银行中每分钟到来顾客数量的分布以及每个顾客需要服务时间的分布
希望找到合适的雇员数
*/

int option(int percents[])
{
	register int i = 0, choice = rand() % 100 + 1, perc;
	for (perc = percents[0]; perc < choice; i++, perc += percents[i]);
	return i;
}

int main()
{
	//每分钟到来的顾客数为0,1,2,3,4的概率
	int arrivals[] = {15,20,25,10,30};

	//需要服务30秒的概率为10%，40秒为5%，以此类推
	int service[] = {0,0,0,10,5,10,10,0,15,25,10,15};


	//每个雇员前排队的时间
	int clerks[] = {0,0,0,0,0};
	int numOfClerks = sizeof(clerks) / sizeof(int);
	
	int customers;
	int t;
	int i;
	int numOfMinutes = 100;
	int x;

	//100分钟里正在等待的顾客所需服务时间的最大值
	double maxWait = 0;
	//当前等待的顾客所需时间和
	double currWait = 0;
	//100分钟里有顾客等待的分钟数
	double thereIsLine = 0;


	Queue<int> simuQ;

	//输出double的精度（两位小数）
	cout.precision(2);

	for (t = 1; t < numOfMinutes; t++)
	{
		cout << "t = " << t;
		
		//该分钟内各个雇员已被分配走的时间
		for (i = 0; i < numOfClerks; i++)
		{
			if (clerks[i] < 60)
				clerks[i] = 0;
			else
				clerks[i] -= 60;
		}

		//选出第t分钟到达的人数
		customers = option(arrivals);


		//选出每位顾客需要的服务时间并放入队列
		for (i = 0; i < customers; i++)
		{
			x = option(service) * 10;
			simuQ.enqueue(x);
			currWait += x;
		}


		//为每个雇员安排需要服务的顾客
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






