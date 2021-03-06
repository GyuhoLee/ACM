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

	int N;
	cin >> N;
	int answer = 0;
	int temp;
	cin >> temp;
	int one = temp;
	int before = temp;
	FUP(i, 1, N - 1)
	{
		cin >> temp;
		if (temp > before)
		{
			answer = max(answer, temp - one);
			before = temp;
		}
		else
		{
			before = temp;
			one = temp;
		}
	}
	cout << answer;

	return 0;
}