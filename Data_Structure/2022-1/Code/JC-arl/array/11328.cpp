#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int N;
	
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		int arr[26] = { 0 }, count = 0;
		cin >> s1;

		for (int j = 0; j < s1.size(); j++)
		{
			arr[s1[j]-'a']++;
		}
		cin >> s2;
		if (s1.size() != s2.size())		//���̰� ���� ������ Impossible
			cout << "Impossible\n";
		else
		{
			for (int j = 0; j < s2.size(); j++)
				arr[s2[j] - 'a']--;
			for (int j = 0; j < s2.size(); j++)
				if (arr[s2[j] - 'a'] != 0)
					count++;
			if (count==0)
			{
				cout << "Possible\n";
			}
			else
			{
				cout << "Impossible\n";
			}
		}
		
	}
	return 0;
}

/*���ڿ� ���� �ִ� 1000,�׽�Ʈ 1000������
2�߹ݺ� ����


*/