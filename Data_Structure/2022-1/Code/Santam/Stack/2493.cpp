#include <iostream>
#include <stack>
using namespace std;

int index[500001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> s;
	int n;
	cin >> n;
	int pop_cnt = 0;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		while (1)
		{
			if (s.empty())
			{
				s.push(temp);
				index[s.size()] = s.size() + pop_cnt;
				cout << "0 ";
				break;
			}
			if (s.top() < temp)
			{
				s.pop();
				pop_cnt++;
			}
			else
			{
				cout << index[s.size()] << " ";
				s.push(temp);
				index[s.size()] = pop_cnt + s.size();
				break;
			}
		}
	}
	return 0;
}

/*
1.�Է� ������ ���� ���� �߿� ���� �ֱٿ� �Էµ� ���� ��ġ�� ����ϴ� ���̶�� �����Ͽ� ���� �ֱٿ� �Էµ� ���� ã�� ���� ������ �̿�

2.n���� �Է¿� ����, ���࿡ s�� ������ ����ִٸ� �Էµ� ���� ���ÿ� �־��ָ鼭 �Էµ� ������ ���� ���� ���⿡ 0�� ���

3.���ÿ� �̹� ���ڰ� �ִٸ� ���� �ֱٿ� �Էµ� ���ں��� ���ʷ� ���Ͽ� �Էµ� ������ ���� ������ ���� pop
--> �Էµ� ������ ���� ������ ������ ���� ���� ���̿� ����, ���� ���̳� �������� + ���,��ġ�� �˱����� pop�� Ƚ���� ���� ī��Ʈ

4.���� �Էµ� ���ں��� ū ���� ���ÿ� �����ϸ� �װ��� ��ġ�� ����ϰ� �Էµ� ���� push�ϸ鼭 �Էµ� ���� ��ġ�� �迭�� ����
*/