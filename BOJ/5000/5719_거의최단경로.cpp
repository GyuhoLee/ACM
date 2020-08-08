#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

int N, M, S, D;
int U, V, P;
int arr[500][500] = { 0, };	//i���� j������ �Ÿ�
int d[500];	//S���� i������ �ּڰ�
bool visited[500];	//i��° ��带 �ּڰ����� ���Ͽ��°�.
vector<int> connect[500];	//i��°���� �� �����ִ� ���� ����
vector<int> road[500];	//S���� i������ �ּ� ��� (ex. 1- 2- 3- 4)
vector<vector<int>> overlab[500];	//�ּڰ��� ��ĥ��� �����س���
int answer;

bool input()
{
	scanf_s("%d %d", &N, &M);
	if (!(N + M)) return false;	// �Ѵ� 0�̸� Ż��
	scanf_s("%d %d", &S, &D);
	/*	�̰ž��� �޸��ʰ� ����. capacity�����ΰ�
	connect->clear();
	road->clear();
	overlab->clear();	
	*/
	for (int i = 0; i < 500; i++)
	{
		connect[i].clear();
		road[i].clear();
		overlab[i].clear();
	}
	while (M--)
	{
		scanf_s("%d %d %d", &U, &V, &P);
		arr[U][V] = P;
		connect[U].push_back(V);
	}
	return true;
}

void find_min()
{
	memset(visited, false, sizeof(visited));
	vector<int> v;	//road�� ���� ����
	answer = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		d[i] = INT_MAX;	//��� ���� �Ÿ��� �ִ�����
	}
	d[S] = 0;	//������� �翬�� 0
	v.push_back(S);
	road[S] = v;	//S������ S�� ����� ��. �̰� ��� �÷������� road�� ����ڴ�
	while (true)	//���ͽ�Ʈ�� �˰���� �����ϴ�
	{
		int cost = INT_MAX;	//�ּڰ� ������ ����
		int node = -1;	//�ּڰ��� ���
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && (cost > d[i]))	//visited�� �̹� ���� ���. ������ ���� �߿��� �ּڰ�
			{
				cost = d[i];
				node = i;
			}
		}
		if (cost == INT_MAX)	//��带 ������ ���Ͽ�����, Ż��(D�� �����ҽ� while���� ������ ������)
		{
			answer = -1;
			return;
		}
		if (node == D)	//�������� ���������� ���� �� ���� �ʿ� ����.
		{
			break;
		}
		visited[node] = true;	//���õ� ���� �ּڰ��� �����Ǿ���.
		for (auto iter = connect[node].begin(); iter != connect[node].end(); iter++)	//�ش� ����κ��� �� �� �ִ� ���� �� ���Է��ϱ�
		{
			if (d[*iter] > d[node] + arr[node][*iter])	//���� ��κ��� �� ª�� �� �� �ִ� ���,
			{
				d[*iter] = d[node] + arr[node][*iter];	//�ش� ���� ����
				road[*iter] = road[node];	//�ش� �������� ��θ� �������ش�.
				road[*iter].push_back(*iter);	//���ݱ����� ��� + �̵��� ���
				overlab[*iter].clear();	//���� ��ġ�� ���͵麸�� �Ÿ��� ª�� ������ clear���ش�.
				if (overlab[node].size())	//���ݱ����� ����� �ּڰ��� ������ (ex. 1 - 3 - 2, 1 - 2  �� ���� �������� overlab���� �ִ�.)
				{
					for (auto iter2 = overlab[node].begin(); iter2 != overlab[node].end(); iter2++)	//����� ������ŭ.
					{
						vector<int> temp = *iter2;	//���͸� �޾ƿ�
						temp.push_back(*iter);
						overlab[*iter].push_back(temp);	//overlab�� �� ��ġ�� ��α��� �־����.
					}
				}
			}
			else if (d[*iter] == d[node] + arr[node][*iter])	//�ּڰ��� �Ȱ���������, �ش� ��θ� ��������� �Ѵ�.
			{
				vector<int> temp = road[node];
				temp.push_back(*iter);
				overlab[*iter].push_back(temp);	//���� ����� overlab�� ��������� ��θ� �߰��Ѵ�.
				if (overlab[node].size())	//�̹� ����� overlab ���� �ִ� ���, �� ���� �߰����־�ߵȴ�.
				{
					for (auto iter2 = overlab[node].begin(); iter2 != overlab[node].end(); iter2++)
					{
						vector<int> temp2 = *iter2;
						temp2.push_back(*iter);
						overlab[*iter].push_back(temp2);
					}
				}
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < road[D].size() - 1; i++)	//road�� 1 - 2 - 3 - 4 �� ���·� �����Ƿ�, i��°���� i + 1��°�� ���� �Ÿ��� ���̴�.
	{
		temp += arr[road[D][i]][road[D][i + 1]];
	}
	answer = temp;

}

void remove_min()
{
	//road�� ����Ǿ��ִ� ��ε��� �����Ѵ�.
	for (int i = 0; i < road[D].size() - 1; i++)
	{
		arr[road[D][i]][road[D][i + 1]] = 0;
		for (auto iter = connect[road[D][i]].begin(); iter != connect[road[D][i]].end(); iter++)
		{
			if (*iter == road[D][i + 1])
			{
				connect[road[D][i]].erase(iter);
				break;
			}
		}
	}

	//���������� overlab�� ����Ǿ��ִ� ��ε��� �����Ѵ�.
	vector<int> temp;
	while (!overlab[D].empty())
	{
		temp = overlab[D].back();
		overlab[D].pop_back();
		for (int i = 0; i < temp.size() - 1; i++)
		{
			arr[temp[i]][temp[i + 1]] = 0;
			for (auto iter = connect[temp[i]].begin(); iter != connect[temp[i]].end(); iter++)
			{
				if (*iter == temp[i + 1])
				{
					connect[temp[i]].erase(iter);
					break;
				}
			}
		}
	}
}

int main()
{
	while(input())
	{
		find_min();
		int temp = answer;
		if (answer != -1)	//���ʿ� ��ΰ� ���� ���� ������ �ʿ� ����.
		{
			while (temp == answer)
			{
				remove_min();
				find_min();
			}
		}
		if (answer == INT_MAX) printf("-1\n");
		else printf("%d\n", answer);
	}


	return 0;
}