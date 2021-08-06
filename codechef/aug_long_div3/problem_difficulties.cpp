#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve1()
{
	set<int> s;
	int x;
	for (int i = 0; i < 4; i++)
	{
		cin >> x;
		s.insert(x);
	}
	return s.size() / 2;
}

int solve()
{
	int a[4] = {0}, cnt = 0;
	vector<bool> v(4, false);
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j and a[i] != a[j] and !v[i] and !v[j])
			{
				v[i] = true;
				v[j] = true;
				cnt++;
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