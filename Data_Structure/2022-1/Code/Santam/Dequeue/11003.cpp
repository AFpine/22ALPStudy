#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<pair<int, int>> d_min;
	int n, l, cnt = 0;
	cin >> n >> l;


	while (cnt < n)
	{
		int temp;
		cin >> temp;
		while (d_min.size()!=0)
		{	
			if (d_min.back().first <= temp)
			{
				pair<int, int> p = { temp,cnt };
				d_min.push_back(p);
				break;
			}
			d_min.pop_back();
		}
		if(d_min.size()==0)
		{
			pair<int, int> p = { temp,cnt };
			d_min.push_back(p);
		}

		if (cnt >= l)
		{
			if (d_min.front().second == cnt - l) d_min.pop_front();
		}

		cout << d_min.front().first << " ";

		cnt++;
	}

	return 0;
}

/*
1.ó���� ��ü �Է� ���� �� �Ϻθ��� ������ ��1�� �Է� �� ���� �������� ������� �޾ƿ� ��2�� ����� ������ ������ ����� ���ڰ� ���ŵǸ� ���ÿ� �� ���� �ִ� ���� ���ڸ� �����Ϸ��� ������ �ð����⵵�� Ŀ���ٴ� ���� ���޾Ҵ�.

2.���� �� ���� �ϳ��� ������ �����ֱ� ���� ����� �����߰�,pair�� �� ������ ���ָ���� �������� ����ߴ�.

3.����, �Ϻθ� ������ ���� size�� 0�̸� �������� �Է��� �޵��� ���־���. �׷��� �������� ������������ ���ڸ� �����ϱ����� ������ ���� �ִ� ���� ���ؼ� �Է°��� push�ߴ�.
==> ���⼭, ó������ ���� �ִ� ���ڸ� �����ϱ� ���� ����ߴµ�, ���, ���� ���� �ּҰ��� ����ϴ� �������⿡, �ԷµǴ� ������ ū ���� ���ȿ� �ִٸ�, ����� �� ���� �ּҰ��� �� �� ���ٴ� �� Ȯ���� �� �־, ����, pop���ְ� �������� �ʾҴ�.

4.���࿡ ������ �������� ����� ���� cnt�� l���� Ŭ������ �Ź� ����Ƿ�, �� ������ ����, c-l�� �ش��ϴ� ��ġ�� ���� �� ���� ���� �����ߴ�.
*/