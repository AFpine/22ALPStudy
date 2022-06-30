#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		if (temp)
		{
			s.push(temp);
		}
		else
		{
			s.pop();
		}
	}
	int result = 0;
	int size = s.size();
	for (int i = 0;i < size;i++)
	{
		result += s.top();
		s.pop();
	}
	cout << result << endl;
	return 0;
}
/*
1. 0�� ��쿣 ���� �ֱ� �߰��� ���ڸ� �����, �� �ܿ� ���ڸ� ���ϸ� �Ǵ� ��� ==> ������ ������ pop,push�� ������� �����ϸ� ���ٰ� �Ǵ�

2. ó�� �ݺ������� ���� n���� ���� 1�� ������ ���� ����

3. result�� �ش��ϴ� ���� ���ϱ� ���� ���ÿ� ���� �����͸� �ϳ��� �����鼭 ���� �����־���
*/