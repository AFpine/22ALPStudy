#include <iostream>

using namespace std;

void Rec(int n,int cnt)
{
	if (n==0)
	{
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "\"����Լ��� ������?\"\n";
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "��� �亯�Ͽ���.\n";
	}
	else
	{
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "\"����Լ��� ������?\"\n";
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		Rec(n-1, cnt+1);
		for (int i = 0;i < cnt;i++) cout << "____";
		cout << "��� �亯�Ͽ���.\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	Rec(n,0);
}

/*
��͸� �̿��ؼ� �ݺ����� �޼����� ����ϴٰ� ������ ��Ͱ� �����Ҷ� ���� ��Ģ���� �޼����� ����ߴ�.
*/