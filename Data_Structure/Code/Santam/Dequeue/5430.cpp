#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp,num_temp;
		int size,cnt=0,str_at = 0;;
		cin >> temp >> size >> num_temp;
		deque<string> d;
		bool chk_R = false , chk_error=false;

		num_temp.erase(num_temp.begin());
		num_temp.erase(num_temp.end()-1);

		while (cnt<size)
		{
			string temp_string="";
			while (num_temp[str_at] != ',')
			{
				if (str_at >= num_temp.size()) break;
				temp_string.push_back(num_temp[str_at]);
				str_at++;
			}
			d.push_back(temp_string);
			str_at++;
			cnt++;
		}
		while (temp.size() > 0)
		{
			if(temp.front()=='R')
			{
				chk_R = !chk_R;
			}
			if (temp.front() == 'D')
			{
				if (d.size())
				{
					if (chk_R) d.pop_back();
					else d.pop_front();
				}
				else
				{
					cout << "error" << "\n";
					chk_error = true;
					break;
				}
			}
			temp.erase(temp.begin());
		}

		if (!chk_error)
		{
			cout << "[";
			int d_length = d.size();
			for (int j = 1;j < d_length;j++)
			{
				if (chk_R)
				{
					cout << d.back() << ",";
					d.pop_back();
				}
				else
				{
					cout << d.front() << ",";
					d.pop_front();
				}
			}
			if(d_length) cout << d.back() << "]\n";
			else cout << "]\n";
		}
	}
	return 0;
}
/*
1.���� �迭�� ���� ������ ���ų� �ȵ����� ������ �ֱ⿡ ����⿡�� �迭�� ���� ���Ű� �Ͼ�⿡ ���� ����ߴ�.

2.�� ���������� �迭�� �ִ� ���� ���� ���¸����� �ذ��� �ƴ� Ư�� ��ȣ�� ���Ե� ���ڿ��� �Է��� �Ǿ� �з��� ����� �Ѵ�.

3.�Էµ� �迭 ���ڿ��� �з��Ҷ� []��ȣ�� �̸� ������ �Ŀ� ,�� �������� ������ �� ���ڸ� ���� �־��־���.

4.R�� D�� �Լ����� R�� ���Ƚ���� ¦������ Ȧ������ �߿��ϱ⿡ üũ ������ ����� �� ������ ���� D�� ��ɿ��� pop�� �ϴ� ��ġ�� ����

5.��� ����� ������ ���Ŀ� �°� ���� �ִ� ���� ������־���.
*/