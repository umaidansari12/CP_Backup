#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ll a[n], pre[n];
	memset(a, 0, sizeof(a));
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			pre[i] = a[i];
		}
		else
		{
			pre[i] = pre[i - 1] + a[i];
		}
	}


	int q, t;
	cin >> q;
	while (q--)
	{
		int cnt = 0, i = 0;
		cin >> t;
		// int idx = upper_bound(a, a + n, t) - a;
		// cout << idx << ' ' << pre[idx - 1] << '\n';
		for (i = 0; i < n; i++)
			if (a[i] <= t)
			{
				cnt++;
			}
			else
				break;
		cout << cnt << ' ' << pre[i - 1] << '\n';

	}


	return 0;
}