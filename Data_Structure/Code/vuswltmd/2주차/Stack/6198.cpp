#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr; // ����Ʈ ���̸� ������ �迭
	int count = 0; // Ȯ�� �� �� �ִ� ����Ʈ ��

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		arr.push_back(num);
	}

	arr.push_back(0);

	reverse(arr.begin(), arr.end());

	stack<pair<int, int>> st; //first..���� second..����
	st.push({ 0, 1000000011 });

	for (int i = 1; i <= n; i++)
	{ 

		while (arr[i] > st.top().second)
		{
			st.pop();
		}

		count = count + i - st.top().first-1;
		//cout <<arr[i]<<": " << "count:" << count << endl;

		st.push({ i, arr[i] });
	}

	cout << count;
	
}