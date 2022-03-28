#include <iostream>
#include <stack>

using namespace std;

int reverse_input[1000000] = { 0 };
int result[1000000] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		reverse_input[n - i - 1] = temp;
	}
	for (int i = 0;i < n;i++)
	{
		while (1)
		{
			if (s.empty())
			{
				result[i] = -1;
				s.push(reverse_input[i]);
				break;
			}
			if (s.top() <= reverse_input[i])
			{
				s.pop();
			}
			else
			{
				result[i]=s.top();
				s.push(reverse_input[i]);
				break;
			}
		}
	}
	for (int i = n - 1;i >= 0;i--)
	{
		cout << result[i] << " ";
	}
}

/*
1. ž ������ ���������� ����� �����ε� �ʹ�. �׷���, ������ �̿��� �Էµ� ���ڿ� ���� ���ÿ� �ִ� ���� ���ϴ� ����� ä���ߴ�.

2. �� ������ ���� ������� �ٸ��� �񱳸� �ϸ鼭 pop�� ī���͸� ���شٰų� ��ġ�� ����� �ʿ䰡 ���ٴ� �� �˾Ҵ�.

3. �Էµ� ���� ������ top���� ũ�ٸ� �ϳ��� pop�� ���־���, �ݴ��� ��쿣 �� ���� �����ϵ��� �߰�, �������� ����� ���� ���� ����ߴ�.
*/