#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve()
{
	ll n, cnt = 0;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	for (ll i = 0; i < n; i++)
	{
		if (s2[i] == '1')
		{
			if (s1[i] == '0')
				cnt++;
			else if (s1[i] == '1')
			{
				if (i - 1 > 0 and s1[i - 1] == '1')
				{
					s1[i - 1] = '0';
					cnt++;
				}
				else if (i + 1 < n and s1[i + 1] == '1')
				{
					s1[i + 1] = '0';
					cnt++;
				}
			}
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
		cout << solve() << '\n';
	}


	return 0;
}