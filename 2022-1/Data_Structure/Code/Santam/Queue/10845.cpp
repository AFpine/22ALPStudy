#include <iostream>

using namespace std;

int que_arr[10001] = { 0 };

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int size = 0;
	int front_pos = 1;
	int back_pos = 1;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int temp_int;
			cin >> temp_int;
			back_pos = front_pos + size;
			size++;
			que_arr[back_pos] = temp_int;
		}
		if (temp == "pop")
		{
			if (size)
			{
				cout << que_arr[front_pos] << "\n";
				front_pos++;
				size--;
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		if (temp == "size")
		{
			cout << size << "\n";
		}
		if (temp == "empty")
		{
			if (size) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		if (temp == "front")
		{
			if (size) cout << que_arr[front_pos] << "\n";
			else cout << -1 << "\n";
		}
		if (temp == "back")
		{
			if (size) cout << que_arr[back_pos] << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}

/*
1. ť�� ����� ������ ��ɿ� ���� �˰� �����ϴ� ������� �Ǵ�, ť�� ���� ���� ���� ���� ������ ����̶�� ���� Ȯ��

2. ť�� ���밡 �� �迭 �ϳ��� �������־���, size,front_position,back_position�� �˱����� ������ �������־���.

3. push������ �Էµ� ���� ���� Ǫ���ϸ鼭 back_pos�� ���� front���� size���� ������ �����ϰ� �� ��ġ�� �Էµ� ���� ����

4. pop������ front�κп��� ���� �����ߵǹǷ� pop���� �ش� ��ġ�� ���ָ鼭 front���� �ϳ��� �÷��־���.

5. ������ ��ɵ��� 2���� ���� ������ Ȱ���� ������ �����ߴ�.
*/