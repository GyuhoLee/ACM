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
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
#define SIZE 1001

int N, M, S, E;	
int u, v, w;	//u -> v�� ����ġ w
vector<pair<int, int>> arr[SIZE];	//	arr[i] = first���� second�� ����ġ
int d[SIZE]; //������������ �� idx node ������ �Ÿ�. ó���� INF������ �ʱ�ȭ �ʿ�
int before[SIZE];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, S });	// S���� ����
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
				before[iter.first] = node;
				pq.push({ d[iter.first], iter.first });
			}
		}
	} // ������ d[i]�� INF�̸� ������ �� ����.
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(&d[0], &d[SIZE], INT_MAX);
	CIN2(N, M);
	while (M--)
	{
		CIN3(u, v, w);
		arr[u].push_back({ v, w });
	}
	CIN2(S, E);
	dijkstra();
	COUT(d[E]);
	ENDL;
	int node = E;
	stack<int> ans;
	while (node)
	{
		ans.push(node);
		node = before[node];
	}
	COUT(ans.size());
	ENDL;
	while (!ans.empty())
	{
		COUT2(ans.top(), "");
		ans.pop();
	}

	return 0;
}