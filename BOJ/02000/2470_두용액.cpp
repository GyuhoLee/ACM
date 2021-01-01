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

int N, a, b, num, ans = INT_MAX;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	int M = N;
	while (M--)
	{
		CIN(num);
		v.push_back(num);
	}
	sort(ALL(v));
	int s = 0, e = N - 1;
	while (s < e)
	{
		num = v[s] + v[e];
		if (abs(num) < ans)
		{
			a = v[s];
			b = v[e];
			ans = abs(num);
		}
		if (num < 0) s++;
		else e--;
	}
	COUT2(a, b);

	return 0;
}