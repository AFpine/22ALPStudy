#include<iostream>
using namespace std;

int main(void)
{
	int N, v, count = 0;		//-100<= v <=100
	int arr[105] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> v;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == v)
			count++;
	}
	cout << count;
	return 0;
}
/*
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // -100 <= v && v <= 100 �̹Ƿ� ������ ������ �� �ִ� ������ �迭�� �߰�
  int N, v, a[201] = {};
  cin >> N;

  // �Է°��� �迭�� ����
  while(N--){
	int t;
	cin >> t;
	// ������ �ε����� �����ϱ� ���� ���� �ε���+100���� �迭�� ����
	a[t+100]++;
  }

  // v�� ������ �迭���� Ȯ��
  cin >> v;
  cout << a[v+100];
}*/