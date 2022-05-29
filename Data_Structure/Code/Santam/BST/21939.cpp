#include <iostream>
#include <set>

using namespace std;


int main()
{
	set<int> ques[101];
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, l;
		cin >> p >> l;
		ques[l].insert(p);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int p, l;
			cin >> p >> l;
			ques[l].insert(p);
		}
		else if (s == "recommend")
		{
			int option;
			cin >> option;
			if (option == 1)
			{
				for (int i = 100;i >= 1;i--)
				{
					if (!ques[i].empty())
					{
						cout << *(--ques[i].end()) << "\n"; break;
					}
				}
			}
			else
			{
				for (int i = 1;i <= 100;i++)
				{
					if (!ques[i].empty())
					{
						cout << *ques[i].begin() << "\n"; break;
					}
				}
			}
		}
		else
		{
			int sol;
			cin >> sol;
			for (int i = 100;i >= 1;i--)
			{
				auto at = ques[i].find(sol);
				if (at!= ques[i].end())
				{
					ques[i].erase(at);
					break;
				}
			}
		}
	}
}
/*
���� �̹��� map�Ἥ �����Ѵ��� Ǯ��������, ���̵�ã���� ������ ���Ƽ� set�Ἥ Ǯ����.
1. set�� ���� �迭 ������ ���� �迭�� ���ڷ� ���� ���� ���̵��̴�.
2. set�� �� �� ���̵� ���� ������ȣ�� insert�ϸ� �ڵ����� ������ �Ǿ��ִ�.
3. add�� �׳� ���� �־��ֱ⸸ �ϸ�ǰ�, recoomand���� �ִ볭�̵��� �ִ� ��ȣ ������ ����Ҷ� set�迭 ���������� Ž���ϸ鼭
set�� ������� ������ �� set�� �����ִ� ��Ҹ� ���, �ּҶ�� �ݴ�� set�迭 ó���������� Ž��, setó���� ���� ���
4. solve���� �ش� ������ȣ�� ����Ʈ���� �����ؾߵǹǷ�, set�迭 ��ü�� Ž���ϸ鼭 �ش� ���� ����
*/