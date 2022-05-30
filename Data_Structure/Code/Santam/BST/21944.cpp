#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define Algo 101
#define Difficult 101
using namespace std;

set<int> ques_no_algo[Difficult]; //recommend2���� �˰��� �з� ���� �ְ� ���̵��� ������ �˾Ƴ��� ���� ����
set<int> ques[Algo][Difficult];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, l, g;
		cin >> p >> l >> g;
		ques[g][l].insert(p);
		ques_no_algo[l].insert(p); 
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (s == "recommend")
		{
			int algorithm_num, option;
			cin >> algorithm_num >> option;
			if (option == 1)
			{
				for (int j = 100; j > 0; j--)
				{
					if (!ques[algorithm_num][j].empty())
					{
						cout << *--ques[algorithm_num][j].end() << "\n";
						break;
					}
				}
			}
			else
			{
				for (int j = 1; j <= 100; j++)
				{
					if (!ques[algorithm_num][j].empty())
					{
						cout << *ques[algorithm_num][j].begin() << "\n";
						break;
					}
				}
			}

		}
		else if (s == "recommend2")
		{
			int option;
			cin >> option;
			if (option == 1)
			{
				for (int j = 100; j > 0; j--)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *--ques_no_algo[j].end() << "\n";
						break;
					}
				}
			}
			else
			{
				for (int j = 1; j <= 100; j++)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *ques_no_algo[j].begin() << "\n";
						break;
					}
				}
			}
		}
		else if (s == "recommend3")
		{
			bool Is_find = false; //ã�Ҵ� ���� ���ο� ���� �÷���
			int difficult_num, option;
			cin >> option >> difficult_num;
			if (option == 1)
			{
				for (int j = difficult_num; j <= 100; j++)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *ques_no_algo[j].begin() << "\n";
						Is_find = true;
						break;
					}
				}
			}
			else
			{
				for (int j = difficult_num - 1; j >= 1; j--)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *--ques_no_algo[j].end() << "\n";
						Is_find = true;
						break;
					}
				}
			}
			if (!Is_find) cout << -1 << "\n"; //�� ã�� ���
		}
		else if (s == "add")
		{
			int p, l, g;
			cin >> p >> l >> g;
			ques[g][l].insert(p);
			ques_no_algo[l].insert(p);
		}
		else if (s == "solved")
		{
			int p,temp; // p�� ã�� ��ġ�� ���̵��� �����ϱ� ����->ques���� ����Ʈ�� �ִ� p�� ����� ����
			cin >> p;
			for (int j = 1; j <= 100; j++)
			{
				auto at=ques_no_algo[j].find(p);
				if (at != ques_no_algo[j].end()) // p�� ã�� ���
				{
					temp = j;
					ques_no_algo[j].erase(at);
					break;
				}
			} // ques_no_algo�� �ִ� p ����
			for (int j = 1; j <= 100; j++)
			{
				auto at = ques[j][temp].find(p);
				if (at != ques[j][temp].end()) // p�� ã�� ���
				{
					ques[j][temp].erase(at);
					break;
				}
			} // ques�� �ִ� p ����
		}
	}
	return 0;
}
/*
�� ������ ���ؼ� ���� ��õ �ý��� 1�� �����ߴµ�, ��� ���⿡�� �˰��� �з��� ���ԵǼ� set���� �ΰ��� ����� �˰��� �з� ������ ������ �Ѵ� �����ߴ�.
1. ques�������� �˰��� �з���,���̵����� ���� �´� �迭 ��ġ�� ������ȣ���� �־���, ques_no_algo���� ���̵� ���θ� ������ �־���.
2. recommend������ �Է¹��� �˰��� �з����� ���̵� ����� ������ ���� Ž���ؼ� Ž�������� ���̵��� ���� �����ִ� ���(������ȣ�� ���� ū��)�� ���, �ݴ��� ��쿣 �ݴ��
3. recommend2������ �˰��� �з� ���� ������ 2�� ������ �����ϰ� ����
4. recommend3������ 2�� �������� ���̵��� ã�� �ݺ����� ������ġ�� ���������.
5. solved������ ques_no_algo���� ������ȣ�� Ž���� ��ġ�� ���̵��� ã��(ques������ ����� ���� �ʿ�) �ش� ��Ҵ� ����,ques������ ���� ����(ã�Ƴ��� ���̵��� Ȱ��)
==> �� solved���� �ð� ���⵵�� Ŭ������ �����ؼ� �޸�������̼����� ������ȣ�� ���̵��� �̸� �����س���� ����������, �׳� �̷��� �ص� �ð� �ʰ� �Ȱɸ��淡 �������ϰ� �̴�� ����
*/