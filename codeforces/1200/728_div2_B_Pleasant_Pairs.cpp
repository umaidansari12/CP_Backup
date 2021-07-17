#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int n, cnt = 0;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i]*a[j]) == (i + j + 2))
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << endl;
	}

	return 0;
}