#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int solve1() {
	long long int n, p, k, cnt = 1;
	cin >> n >> p >> k;
	ll a[n];
	for (long long int i = 0; i < n; i++)
		a[i] = i;
	bool flag = false;
	for (long long int i = 0; i < k; i++)
	{
		for (long long int j = 0; j < n; j++)
		{
			if ((a[j] % k) == i and a[j] == p)
			{
				//return cnt;
				flag = true;
				break;
			}
			else if ((a[j] % k) == i)
				cnt++;
		}
		if (flag)
			break;
	}
	return cnt;
}

ll solve() {
	ll n, p, k, cnt = 1;
	cin >> n >> p >> k;

	ll a[n];
	for (ll i = 0; i < n; i++)
		a[i] = i;
	for (ll i = 0; i < k; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if ((a[j] % k) == i and a[j] == p)
			{
				return cnt;
			}
			else if ((a[j] % k) == i)
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
	while (t--) {
		cout << solve1() << '\n';
	}

	return 0;
}