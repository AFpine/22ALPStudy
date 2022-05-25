#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main()
{
	multiset<int> b;
	vector<pair<int, int>> jew;
	int n, k;
	long long res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		jew.push_back(make_pair(v, m));
	}
	sort(jew.begin(), jew.end(),greater<>());
	for (int j = 0;j < k;j++)
	{
		int temp;
		cin >> temp;
		b.insert(temp);
	}
	for (auto cnt = jew.begin();cnt != jew.end();cnt++)
	{
		if (b.empty()) break;
		auto at = b.lower_bound(cnt->second);
		if (at == b.end()) continue;
		else b.erase(at);
		res += cnt->first;
	}
	cout << res;
	return 0;
}
/*
������ ��ġ�� ���� ������ �����ϰ� ������� ���濡 �´��� �־� Ȯ���Ѵ�. ������ �� ������ �����Ѵ�
1. ������ ������ ������ ���Ϳ� ������ ������ ������ multiset�� �����.
2. ������ ������ �ΰ��� �̹Ƿ�  pairȰ���� ����, ������ ������ �ֱ⸸ �ϸ� �ڵ� ���ĵǹǷ� �׳� �־��ش�.
==> ���⼭ ������ ������ multimap�� �ȳִ� ������ �־��ٶ����� ����� �ð����⵵�� �ʹ� ũ�� ������ o(1)�� vector�̿�
3. 2������ �� �Ŀ��� ���� ��ġ�� ���� �������� ������������ ������ �ߵ��� �ִ� ���Զ� ���� ������ �� ������ multiset���� erase���ش�.
*/