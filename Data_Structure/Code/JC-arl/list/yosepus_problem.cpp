#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	queue<int> qu1, qu2, prt;
	int n, k, count = 0;
	cin >> n >> k;

	for (int j = 1; j <= n; j++)
	{
		qu1.push(j);
	}
	for (int i = 1;; i++)
	{
//1234567
//3 - 124567
//36 - 12457
//362 - 1457
//3627 - 145
		if (qu1.empty() && qu2.empty())
			break;
		if (i % k == 0)
		{
			prt.push(qu1.front());
			//cout <<"prt�� 3��°����"<<prt.back() << endl;
			qu1.pop();
			count++;
			if (qu1.empty())
			{
				qu1.swap(qu2);

			}
		}
		else {

			qu2.push(qu1.front());
			qu1.pop();
			if (qu1.empty())
			{
				qu1.swap(qu2);

			}
		}
	}
	cout << '<' << prt.front();
	prt.pop();
	for (int j = 1; j < n; j++)
	{
		cout << ", " << prt.front();
		prt.pop();
	}
	cout << '>';
	return 0;
}

/*
�Է�: �ο�n, ���ŵ� ��ȣ k
���: ���ŵǴ� ��ȣ���� ����

-���� ó���� ����Ǿ 3��° ���� �ش��ϴ� ��ȣ�� ���ŵǰ� 
���ŵ� ��ȣ�� �迭 �Ǵ� ť�� �ִ´�

1.�ο�n, ���ŵ� ��ȣ k
1234567

2.




*/