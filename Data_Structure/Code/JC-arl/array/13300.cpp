#include<iostream>
using namespace std;

int main(void)
{
	
	int N, S, K, Y, count = 0;//s-����, y-�г�
	int arr[2][7] = { 0 };
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> Y;
		arr[S][Y]++;
	}
	for (int j = 0; j < 2; j++)
	{
		for (int i = 1; i <= 6; i++)
		{
			if (arr[j][i] % K)//������ �������� ���� ��
				count = count + ((arr[j][i]) / K) + 1;
			else 
				count = count + (arr[j][i] / K);
		}
	}
	cout << count;
	return 0;
}

/*2��3�� ��-��, ��-�� �����
 1~6�г����, �ѹ濡 �Ѹ� ��ġ����,���� �гⳢ���� ��ġ
 �ѹ濡 �ִ��ο���-k ���� �ּ� ���� ���
 
 �Է�-���� �л���-N , �� �ִ� �ο�-K
 +����S �� �г�Y ����
 S�� 0,1  0-����, 1-����;
 ���-�ּ����� �� ��
*/