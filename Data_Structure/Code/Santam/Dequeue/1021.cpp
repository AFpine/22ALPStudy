#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int result = 0;
	queue<int> q;

	for (int i = 1;i <= n;i++)
	{
		q.push(i);
	}

	for (int i = 0;i < m;i++)
	{
		int temp;
		cin >> temp;
		int shift_cnt = 0;
		while (q.front() != temp)
		{
			q.push(q.front());
			q.pop();
			shift_cnt++;
		}
		if (shift_cnt > (q.size() - shift_cnt))  result += (q.size() - shift_cnt);
		else result += shift_cnt;
		q.pop();		
	}

	cout << result<<endl;

	return 0;
}

/*
1.ť���� ������ ���� pop�ؾ� �Ǵ� ���� front�κ� ���̱� ������ ť�� �ذ��ص� �ȴٰ� ����

2.���� n������ ���� ť�� �ְ� ��� front�κ��� pop�ؼ� back�κ����� push�ذ��鼭 temp�� ���ϴ� ��, pop�� Ƚ���� ī��Ʈ ���ش�.

3.front���� temp�� ������ �׵��� pop�� Ƚ���� size������ pop�� Ƚ���� �� ���� ���� ���ϸ� ���� shift����� ������ shift������ ��� �ּ� �������� �� �� �ִ�.

4.�� ���̽� ������ �ּ� ���� ����� result�� �����ְ� �������� ���
*/