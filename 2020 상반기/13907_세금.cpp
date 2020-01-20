#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int N, M, K;
int S, D;
int arr[1001][1001]; // i���� j������ �������� �Ÿ�(1������)�� ��Ƶ�. �⺻�� 0�̴�
int d[1001][1001]; // S���� i���� ���� j�� ���ļ� �Ÿ�. 
int minD[1001]; // �̰� S���� i���� �ּڰ�. �ֳĸ� d[i][j]�� j�� ���������� �����ϱ� ������, �� ���� ���� ��������� ���� ������ �����ٴ� �۾ƾ� �����ִ�.
vector<int> connect[1001]; // �� ��忡�� �� �� �ִ� ��带 �����س���.
int totalK = 0; //k�� ��� ������. w���� �����ϴ°ͺ��� �̰� ����.

void input()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 0;
			d[i][j] = 0;
		}
	}
	scanf_s("%d %d %d", &N, &M, &K);
	scanf_s("%d %d", &S, &D);
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		scanf_s("%d %d %d", &a, &b, &w);
		arr[a][b] = w;	//�� ���� �Ÿ� ����
		arr[b][a] = w;
		connect[a].push_back(b);	//�� ���� ��� ����
		connect[b].push_back(a);
	}
}

void find_road()
{
	for (int i = 1; i <= N; i++)
	{
		minD[i] = INT_MAX;	//�⺻���� �ִ�
	}
	minD[S] = 0;	//ù �������� 0�̴�.
	for (auto iter = connect[S].begin(); iter != connect[S].end(); iter++)
	{
		d[*iter][1] = arr[S][*iter];	//���� 1���� �� ���� �����س���.
	}
	for (int j = 1; j < N; j++)	//j�� �ۿ� �־�� �ȴ�. �׸��� N - 1�� ������ �������� �ϸ� ��.
	{
		for (int i = 1; i <= N; i++) //��� ��� Ȯ��
		{
			if (d[i][j]) // ���� ����Ǿ� �ִ� ��쿡��.
			{
				for (auto iter = connect[i].begin(); iter != connect[i].end(); iter++)	// i���� �� �� �ִ� ���� Ȯ��.
				{
					if (minD[*iter] > d[i][j] + arr[i][*iter])	// �����س��� ������ �� ��������
					{
						d[*iter][j + 1] = d[i][j] + arr[i][*iter];	//j���� 1�� �� ���� ���� �Ἥ, iterator�� ����Ű�� �������� �� ����
						minD[*iter] = d[*iter][j + 1];	//�ּڰ� ����
					}
				}
			}
		}
	}

	// �Ʒ��� �ʱ� �ּҰŸ� ����. N���� ���� ������ �� �� �ִ� ���� �ִ��� ������ ������ ���� �� ���� ����.
	int answer = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		if (d[D][i])
		{
			answer = min(answer, d[D][i]);
		}
	}
	printf("%d\n", answer);

}

void printK()
{
	int num;
	scanf_s("%d", &num);
	totalK += num;	//totalK ���� �����ȴ�.
	//�Ʒ� ��� ������ �ʱ�� ����.
	int answer = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		if (d[D][i])
		{
			answer = min(answer, d[D][i] + totalK * i);	//j�� ���� ���� �����̱� ������, ������ ������ �����ָ� �ȴ�.
		}
	}
	printf("%d\n", answer);
}

int main()
{
	input();
	find_road();
	while (K--)
	{
		printK();
	}

	return 0;
}