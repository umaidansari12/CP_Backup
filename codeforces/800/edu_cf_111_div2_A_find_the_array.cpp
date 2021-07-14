#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int s;
	cin >> s;
	return ceil(sqrt(s));
	int count = 0, place = 1;
	while (s > 0)
	{
		s -= place;
		count++;
		place += 2;
	}
	// int count = 1;
	// int max = 1;
	// int val = 1;
	// while (max < s)
	// {
	// 	val += 2;
	// 	count++;
	// 	max += val;
	// }
	return count;
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