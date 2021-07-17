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

int minNumberofJumpsTopDown(vector<int>&a, int i, int n, vector<int>&dp)
{
	if (i == n - 1)
		return 0;//means we have reached end of the array and we need 0 steps to reach here
	if (i >= n)
		return INT_MAX;//reached outside the boundary so return infinity
	if (dp[i] != -1)
		return dp[i];
	int steps = INT_MAX, maxJumps = a[i];
	for (int jump = 1; jump <= maxJumps; jump++)
	{
		int next_idx = i + jump;//next index would be current index + jump
		int subProblem = minNumberofJumpsTopDown(a, next_idx, n, dp);
		if (subProblem != INT_MAX)
			steps = min(steps, 1 + subProblem);
	}
	dp[i] = steps;
	return dp[i];
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
		vector<int> a(n), dp(n, -1);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << minNumberofJumpsTopDown(a, 0, n, dp) << endl;
	}

	return 0;
}