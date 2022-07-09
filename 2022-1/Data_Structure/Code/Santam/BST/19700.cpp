#include <iostream>
#include <set>
#include <map>

using namespace std;

multiset<int> team;
map<int,int, greater<int>> student_h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp_h, temp_k;
		cin >> temp_h >> temp_k;
		student_h.insert(make_pair(temp_h,temp_k));
	}
	for (auto &cnt:student_h)
	{
		int temp = cnt.second - 1;
		auto at = team.lower_bound(temp);
		if (team.empty())
		{
			team.insert(1);
			continue;
		}// team�� ��� ������ ���ο� �� ����
		if(at==team.end()) //lower_bound�� �ش� ������ ���ų� ū������ ���� ù��° ��Ҹ� ��ȯ�ϴ� �ǵ�, ��ȯ���� teeam.end()�� �ش� ������ ū���� ���ٴ� ���̹Ƿ� ���� ū ��Ҹ� ����� ī��Ʈ
		{
			int temp2 = *--team.end(); //ū ���� ���� ���� ���� ���� ���� ���� �� ����-> Ű ū ����� ������ ����� ���� �ʱ⿡..
			team.erase(--team.end());
			team.insert(temp2 + 1);
			continue;
		}
		if (at == team.begin()) //ã�� ���� ó�� ����϶��� �Է��ߴ� ���� ���� ���� ����� ���� �����Ƿ�-> �� ��쿡�� � ���� ������ Űū ������Ƽ� Ż���Ѵ�.
		{
			if (temp < *team.begin())
			{
				team.insert(1);
				continue;
			}
		}
		int temp3 = *at; //���� ��찡 �ƴ϶�� lower_bound�� �ش�Ǵ� ���� ã�� ���̹Ƿ�, �ش� ��ġ ���� �����ϰ� �� �ش� ��ġ�� +1�� ī��Ʈ �ؼ� �ٽ� ����
		team.erase(at);
		team.insert(temp+1);
	}
	cout << team.size();
	return 0;
}