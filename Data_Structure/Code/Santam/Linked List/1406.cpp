#include <iostream>

using namespace std;
char dat[600001] = { 'A' };
int pre[600001] = { 0 };
int nxt[600001] = { 0 };



int main()
{
	string n;
	int num;
	cin >> n;
	cin >> num;
	fill(pre, pre + 60000, -1);
	fill(nxt, nxt + 60000, -1);

	for (int i = 1;i <= (signed)n.length();i++)
	{
		dat[i] = n[i - 1];
		pre[i] = i-1;
		nxt[i - 1] = i;
	} 
	int length = n.length();
	int cusor = length;
	int data_end = length;
	for (int i = 0;i < num;i++)
	{
		char temp;
		cin >> temp;
		switch (temp)
		{
		case'L':
			if(pre[cusor] != -1) cusor=pre[cusor];
			break;
		case'D':
			if (nxt[cusor] != -1) cusor=nxt[cusor]; 
			break;
		case'B':
			if (pre[cusor] != -1)
			{
				nxt[pre[cusor]] = nxt[cusor];
				if(nxt[cusor]!=-1)pre[nxt[cusor]] = pre[cusor];
				length--;
				cusor = pre[cusor];
			}
			break;
		case'P':
			cin >> dat[data_end + 1];
			pre[data_end + 1]=cusor;
			nxt[data_end + 1]=nxt[cusor];
			if (nxt[cusor] != -1)pre[nxt[cusor]] = data_end + 1;
			nxt[cusor] = data_end + 1;
			length++;
			data_end++;
			cusor = nxt[cusor];
			break;
		default:
			break;
		}	
	}
	int at = nxt[0];
	for (int i = 1;i <= length;i++)
	{
		if (at != -1)
		{
			cout << dat[at];
			at = nxt[at];
		}
	}


	return 0;
} //�� �ڵ忡�� cusor�� ������ ����ϼ� �ۿ� ���ٴ� ���� if������ �ۼ��ؼ� c6385 ��� �ذ��� �� �־����� �ٸ� ����� ���� �ذ�å�� ���� ���� ã�ƺ����� �̴�� �����մϴ�.