#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int ans = n * a;
	if (b >= 0)
	{
		ans += (n * b);
		return ans;
	}
	else
	{
		int count = 1;
		for (int i = 1; i < n; i++)
		{
			if (s[i] != s[i - 1])
				count++;
		}
		ans += (count / 2 + 1 ) * b;
	}
	return ans;
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