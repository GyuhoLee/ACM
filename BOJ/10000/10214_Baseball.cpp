#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0;
		int n, m;
		FUP(i, 1, 9)
		{
			cin >> n >> m;
			a += n;
			b += m;
		}
		string str;
		if (a > b) str = "Yonsei";
		else if (a == b) str = "Draw";
		else str = "Korea";
		cout << str << '\n';
	}

	return 0;
}