#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// codeforces 256 div2 d problem

// binary search brute force 1800

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// int t;
	// cin >> t;
	// while (t--)
	// {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			a.push_back(i * j);
	}
	sort(a.begin(), a.end());
	cout << a[k - 1] << '\n';
	//}



	return 0;
}