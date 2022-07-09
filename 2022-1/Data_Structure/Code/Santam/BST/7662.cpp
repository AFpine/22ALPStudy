#include <iostream>
#include <set>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i <T; i++)
	{
		int input;
		cin >> input;
		multiset<int> s;
		for (int j = 0; j < input; j++)
		{
			char option;
			int n;
			cin >> option >> n;
			if (option == 'I')
			{
				s.insert(n);
			}
			else
			{
				if (s.empty()) continue;
				if (n==1)
				{
					s.erase(--s.end());
				}
				else
				{
					s.erase(s.begin());
				}
			}
		}
		if (s.empty()) cout << "EMPTY\n";
		else cout << *(--s.end()) << " " << *s.begin() << "\n";
	}
}

/*
�켱 ���� ť�� �����ϱ� ���� ����Ʈ�� Ư���� �Է��ϸ� ������ ���ְ� �ߺ����� �� �� �ִٴ� ������ multiset�� �̿��� �����ϸ� ���ٰ� ����
1. �ִ밪�� multiset�� �� ������ �����̰�, �ּҰ��� �� ó�� �����̱⿡ ������ �����ϰ� ����.. ���Ҹ� ����� ������ �˾Ƽ� ���ĵȴٴ� �� ���̴�
*/