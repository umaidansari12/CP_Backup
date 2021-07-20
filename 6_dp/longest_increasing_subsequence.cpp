#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int longestIncreasingSubsequence(vector<int>&a, int idx, int n, int parent)
{
	if (idx == n)
		return 0;
	if (a[idx] > parent)
		return max(1 + longestIncreasingSubsequence(a, idx + 1, n, a[idx]), longestIncreasingSubsequence(a, idx + 1, n, parent));
	else
		return longestIncreasingSubsequence(a, idx + 1, n, parent);
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << longestIncreasingSubsequence(a, 0, n, INT_MIN) << endl;
	}


	return 0;
}