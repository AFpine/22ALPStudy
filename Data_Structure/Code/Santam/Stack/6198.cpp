#include <iostream>
#include <stack>

using namespace std;

long long int index[80001] = { 0 };
long long int reverse_input[80001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	stack<long long int> s;
	long long int result = 0;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		long long int temp;
		cin >> temp;
		reverse_input[n-i-1] = temp;
	}
	for (int i = 0;i < n;i++)
	{
		long long int pop_cnt = 0;
		while(1)
		{
			if (s.empty())
			{
				result += pop_cnt;
				s.push(reverse_input[i]);
				index[s.size()] = pop_cnt;
				break;
			}
			if (reverse_input[i] > s.top())
			{
				pop_cnt += index[s.size()]+1;
				s.pop();
			}
			else
			{
				result += pop_cnt;
				s.push(reverse_input[i]);
				index[s.size()] = pop_cnt;
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}

/*
1. �ٷ� ���� �ܰ��� ž�� ���� ������� �����Ǿ� ������ �̿��Ͽ� �Էµ� ���� ���ÿ� �ִ� ���� �����ָ� �ذ�

2. �Էµ� ������ ���� ������ pop�� ���ָ� ī��Ʈ�� ���ְ� �Էµ� ������ ū���� ������ top�� ������ ī��Ʈ�Ѱ� ����� �����ִ� ���

3. �� �������� ž�� ���̰� 10����� �ȴٴ� ���� ������ �ʿ䰡 �־��ٰ� ����
==> �̰ɷ� 2�� Ʋ�Ƚ��ϴ�...
*/