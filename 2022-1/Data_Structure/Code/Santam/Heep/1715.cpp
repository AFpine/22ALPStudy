#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<long long, vector<long long>, greater<long long>> q;
	int n;
	long long pre,res=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	if (n >= 2)
	{
		for (int i = 0; i < n - 1; i++)
		{
			long long num_1 = q.top(); q.pop();
			long long num_2 = q.top(); q.pop();
			res += num_1+num_2;
			q.push(num_1+num_2);
		}
	}
	cout << res;
	return 0;
}
/*
�� ������ ������ ��ģ ī�带 �ٽ� �켱 ���� ť�� �־ �񱳰� �Ǿ�� �ȴٴ� ���̴�.
1. ī�� ������ ������ �ּ� ���� �ִ´�.
2. n�� 1�� ���� 0�̶�� ���� �����ϰ�, n==2���ʹ� �켱 �������� ���� ���� �� ī�� ������ ������ ���� ���� ����� ���Ѵ�.
3. 2�� �������� ����� ���� �� ī�� ������ ���� �ٽ� �ּ� ���� �ִ´�.==> �� ī�� ������ ���� ī�� ������ �ּҴ� �ƴϱ� ������
*/