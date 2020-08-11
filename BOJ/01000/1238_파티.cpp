#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
#define SIZE 1001
#define INF 11111111
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E, S;	//V : Node�� ��, E : Edge�� ��, S : ������
int u, v, w;	//u -> v�� ����ġ w
vector<pair<int, int>> arr[SIZE], arr2[SIZE];	//	arr[i] = first���� second�� ����ġ
int d[SIZE], d2[SIZE]; //������������ �� idx node ������ �Ÿ�. ó���� INF������ �ʱ�ȭ �ʿ�
int answer = 0;

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, S });	// S���� ����
	d[S] = 0;
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d[node]) continue;
		d[node] = distance;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push({ d[iter.first], iter.first });
			}
		}
	} // ������ d[i]�� INF�̸� ������ �� ����.
}

void dijkstra2()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, S });	// S���� ����
	d2[S] = 0;
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d2[node]) continue;
		d2[node] = distance;
		for (auto iter : arr2[node])
		{
			if (d2[iter.first] > d2[node] + iter.second)
			{
				d2[iter.first] = d2[node] + iter.second;
				pq.push({ d2[iter.first], iter.first });
			}
		}
	} // ������ d[i]�� INF�̸� ������ �� ����.
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(d, d + SIZE, INF);
	fill(d2, d2 + SIZE, INF);
	CIN3(V, E, S);
	while (E--)
	{
		CIN3(u, v, w);
		arr[u].push_back({ v, w });
		arr2[v].push_back({ u, w });
	}
	dijkstra();
	dijkstra2();

	FUP(i, 1, V) answer = max(answer, d[i] + d2[i]);
	COUT(answer);

	return 0;
}