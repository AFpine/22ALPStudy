#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
//ó�� ������ map���� �״ٰ� �� Ǯ����.. ���� �� ������ �� �ð��ʰ� .. �ڵ庸�� �ذ��ϴ� �� ������?
pair<int, int> jewel[300002];
multiset<int> bag;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long sum = 0; // ��ģ ���� �� ��
	int n, k;
	cin >> n >> k;
	

	for (int i = 0; i < n; i++)
	{
		cin >> jewel[i].second >> jewel[i].first;
	}
	sort(jewel, jewel + n);

	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		bag.insert(c);
	}

	for (int i = n-1; i >= 0; i--)
	{
		int m, v;
		m = jewel[i].second;
		v = jewel[i].first;

		auto it = bag.lower_bound(m);
		if(it == bag.end()) continue;
		sum = sum + v;
		bag.erase(it);
	}
	cout << sum;
}


//#include <iostream>
//#include <set>
//#include <map>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	map<int, int> mp;
//
//	int n; //���� ��
//	int k; //������ ��
//
//	long long x = 0;// ��ģ ���� ����;
//
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		int m, v; //������ ����, ����
//		cin >> m >> v;
//		mp[v] = m;
//	}
//	for (int i = 0; i < k; i++)
//	{
//		int c; // ���濡 ���� �� �ִ� ����
//		cin >> c;
//
//		auto it1 = prev(mp.end());
//		while (1)
//		{
//			if (it1->second <= c)
//			{
//				x = x + (int)(it1->first);
//				mp.erase(it1);
//				break;
//			}
//			else
//			{
//				if (it1 == mp.begin()) break;
//				it1 = prev(it1);
//			}
//		}
//	}
//	cout << x;
//}