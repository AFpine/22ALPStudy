#include<iostream>
#include<queue>
using namespace std;
int main(void)
{
	int n;
	queue<int> qu;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		qu.push(j);
	}
	for (int i = 1;; i++)
	{
		if (qu.size() == 1)
			break;
		if (i % 2 == 0)//¦��
		{
			int num;
			num = qu.front();
			qu.push(num);
			qu.pop();

		}
		else			//Ȧ��
		{
			qu.pop();
		}
	}
	cout << qu.front();

	return 0;
}

/*
�Է�: ù°�ٿ� ���� 1~n�����Ǽ�
���: ������ �ǾƷ��� �ű�� �ؼ� ������ ���� ī���� ��ȣ ���
-ť�� ���Լ����̰� ��,�ڷ� ������ �� ������ ť�� ����Ѵ�.
���� ������ 1�� front_point �� �Ʒ��� n�� rear_point �ؼ�
�����°��� front�� �����ѵ� pop �׸��� �״��� ������ ī�嵵 front�� 
�����ѵ� ������ ���� �� rear�� �ְ� front pop �ؼ� size�� 1�϶�
���� ������ ���

1.n�� �Է�

2.���� �ݺ����� ���� queue�� ����� 1�ϋ� �극��ũ

3.������ front �ǾƷ���rear 

4.1���� ���� ������ ������ �״��� 3
���� Ȧ�������� ������ �׸��� ¦������ ������
=> �ݺ����� �� 1�϶� Ȧ������ ������
*/