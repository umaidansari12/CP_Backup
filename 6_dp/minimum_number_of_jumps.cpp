#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int minNumberofJumps(vector<int>&a, int i, int n)
{
	if (i == n - 1)
		return 0;
	if (i >= n)
		return INT_MAX;
	int maxJump = a[i], ans = INT_MAX;
	for (int jump = 1; jump <= maxJump; jump++)
	{
		int next_idx = i + jump;
		int subProblem = minNumberofJumps(a, next_idx, n);
		if (subProblem != INT_MAX)
			ans = min(ans, 1 + subProblem);
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>	t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << minNumberofJumps(a, 0, n) << endl;
	}

	return 0;
}