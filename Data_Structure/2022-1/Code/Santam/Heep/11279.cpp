#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t) q.push(t);
		else
		{
			if (q.empty()) cout << 0 << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}
/*
�⺻ ������ �ּ� �� ������ ���� ����, ���� ���� ����
*/