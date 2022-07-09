#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> lower_n;
	priority_queue<int, vector<int>, greater<int>> upper_n;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (lower_n.empty() || lower_n.top() > t) lower_n.push(t); //lower�� ���쿣 �׳� �־��ָ� �ǰ�, �װ� �ƴϸ� ���ؼ� t�� ������ �־��ش�.
		else upper_n.push(t); // ���� ��찡 �ƴϸ�, t�� lower�� top���� ũ�ų� �����Ƿ� upper�� �ִ´�.
		int op = lower_n.size() - upper_n.size();
		switch (op)
		{
		case 2:
			upper_n.push(lower_n.top());
			lower_n.pop();
			cout << lower_n.top() << "\n";
			break;
		case -2: 
			lower_n.push(upper_n.top());
			upper_n.pop();
			cout << lower_n.top() << "\n"; // lower�� upper�� ���� �ڵ带 �����ϸ� ����� �������Ƿ� ������ ���� ���� lower���
			break;
		case -1:
			cout << upper_n.top() << "\n";
			break;
		default: //case�� 1�� ��쵵 ������ 0�� ��쿡�� ���� ���� ������ �ǹǷ� default�� ����
			cout << lower_n.top() << "\n";
			break;
		}
	}
	return 0;
}

/*
�� ������ ���̵��� �ּ����� �ִ����� ���� ���� ���������� �׻� �����߿� �ϳ��� ������� ������ �ϴ� �� �����ߴ�.
1. ó���� �޴� t���� �ϴ� lower�� �־��ְ� �� �������ʹ� lower�� top�� �����ش�.
2. lower�� top���� ������ lower��, �׷��� ������ upper�� �־��ش�.
3. ��� ���� �׻� ǥ���ϱ� ���ؼ� lower�� upper�� ���������̰� 2�̻󳪸� ������ ��߳��⶧���� ����� ū ������ ���������� top�� ���Ҹ� �̵���Ų��.
4. 1~3�� �ݺ��ϴµ� �ݺ��Ҷ����� ���� ������ش�. ���� ������ ���̰� 2�̻��̸� ����� ���� ����� lower.top��� 1���� ���̳��� ū ���� top�� ���, ������ lower.top�� ����Ѵ�.
*/