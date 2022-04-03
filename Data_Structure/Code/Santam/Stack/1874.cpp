#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int> s;
	vector<string> v;
	bool chk_no = false;
	int n;
	cin >> n;
	int n_state = 1;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		if (temp >= n_state)
		{
			for (int j = n_state;j <= temp;j++)
			{
				s.push(j);
				v.push_back("+");
			}
			n_state = s.top()+1;
			v.push_back("-");
			s.pop();
		}
		else
		{
			if (s.top() == temp)
			{
				v.push_back("-");
				s.pop();
			}
			else
			{
				chk_no = true;
				break;
			}
		}
	}
	if (!chk_no)
	{
		for (int i = 0;i < v.size();i++)
		{
			cout << v[i] << "\n";
		}
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
/*
1. 1�������� n���� ������� push�� ��Ű�ٰ� �Էµ� ���ڿ� ���� pop�� ����� �Ǳ� ������ ������ ���ÿ� ����������� push�� ���־����� ����ϱ� ���� n_state�� ������ �������.

2. �� ������ ������������ push�� �ϱ⿡ �Էµ� ���ں��� ���� ���� push�Ǿ�� �Ѵٸ� push�� �����ʰ� pop�� ���ش�.

3. 2�� �������� pop�� �����Ҷ� pop�ϴ� ���ڰ� �Էµ� ���ڿ� �ٸ��ٸ� ������ �ȵǱ� ������ NO�� ��µǰ� �� ��� �ݺ����� ����ȴ�.

4. ���� �Ϸõ� ������ ���ļ� ����� push�� pop�� ������ ���� ���� v�� ������ �����ϰ� ������� ����Ѵ�.
*/