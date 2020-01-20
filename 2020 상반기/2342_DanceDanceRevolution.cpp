#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num = 1;	//�׳� �Է¹��� ����
int cnt = 0;	//������ ���� ���� ī����
int arr[100001][5][5];	//i��°���¿���, j�� k�� �� ���� ����. ���� ������ ��� �� ���°� ����
int answer = 1000000;

void input()
{
	scanf_s("%d", &num);
}

void DP()
{
	//ó�� �Է��� ������ �� �ϳ��� ������� �Űܾ� ��.(2)
	if (cnt == 1)	
	{
		arr[1][num][0] = 2;
		return;
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)	//��� �� ���� Ȯ��
		{
			if (arr[cnt - 1][i][j])	// ������ �� ���°� �����ϴ� ���,
			{
				if (i == num || j == num)	//���� �� ���� �� ���̶� ���� ���� ��� �ִٸ�, �� ���´� ������ �ʰ� �� 1�� �����ָ� �ȴ�.
				{
					//if else���� ���� ������, ������ �ٸ� �� ���¿��� �Ȱ��� �̹� �� ���°� �� �� �����Ƿ�, �� ���� �ּڰ����� ������ߵȴ�. 
					if (!arr[cnt][i][j]) arr[cnt][i][j] = arr[cnt - 1][i][j] + 1;
					else arr[cnt][i][j] = min(arr[cnt][i][j], arr[cnt - 1][i][j] + 1);
				}
				else
				{
					//�� if else���� j�� �ű�� ��.
					if (!j) // j�� �ʱ� ����(0)�̸� ������ ���� 2�̴�.
					{
						arr[cnt][i][num] = arr[cnt - 1][i][j] + 2;
					}
					else 
					{
						int temp = (abs(j - num) == 2) ? 4 : 3; // ������ ���� ���ֺ��� ������, ���̴� 2�̴�.

						//if else���� ���� ������, ������ �ٸ� �� ���¿��� �Ȱ��� �̹� �� ���°� �� �� �����Ƿ�, �� ���� �ּڰ����� ������ߵȴ�.
						if (!arr[cnt][i][num]) arr[cnt][i][num] = arr[cnt - 1][i][j] + temp;
						else arr[cnt][i][num] = min(arr[cnt][i][num], arr[cnt - 1][i][j] + temp);
					}

					//�̰��� i�� �ű�� ��.
					int temp2 = (abs(i - num) == 2) ? 4 : 3;	// ������ ���� ���ֺ��� ������, ���̴� 2�̴�.

					//if else���� ���� ������, ������ �ٸ� �� ���¿��� �Ȱ��� �̹� �� ���°� �� �� �����Ƿ�, �� ���� �ּڰ����� ������ߵȴ�.
					if (!arr[cnt][num][j]) arr[cnt][num][j] = arr[cnt - 1][i][j] + temp2;
					else arr[cnt][num][j] = min(arr[cnt][num][j], arr[cnt - 1][i][j] + temp2);
				}
			}
		}
	}
}

void find()
{
	//�ٷ� 0�� �Է¹��� ���.
	if (cnt == 1)
	{
		answer = 0;
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[cnt - 1][i][j])	//0�� �ƴ� ��쿡��
			{
				answer = min(arr[cnt - 1][i][j], answer);	//��� �� ���¸� Ȯ��.
			}
		}
	}
}

int main()
{
	while (num)
	{
		input();
		cnt++;
		DP();
	}
	find();
	printf("%d", answer);

	return 0;
}