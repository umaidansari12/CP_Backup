#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isNotSafe(vector<vector<int>> &a, int i, int j, int n, int dist) {
	if (i < 0 || j < 0 || i >= n || j >= n || (a[i][j] != 0 && a[i][j] <= dist))
		return true;
	return false;
}



void dfs(vector<vector<int>> &a, int i, int j, int n, int dist = 1) {
	if (isNotSafe(a, i, j, n, dist))
		return;
	a[i][j] = dist;
	dfs(a, i - 1, j, n, dist + 1);
	dfs(a, i + 1, j, n, dist + 1);
	dfs(a, i, j - 1, n, dist + 1);
	dfs(a, i, j + 1, n, dist + 1);
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					a[i][j] = 0;
					dfs(a, i, j, n);
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > 1)
					ans = max(ans, a[i][j] - 1);
			}
		}
		cout << ans << endl;

	}


	return 0;
}

class Solution {
public:
	bool isNotSafe(vector<vector<int>> &a, int i, int j, int n, int dist) {
		if (i < 0 || j < 0 || i >= n || j >= n || (a[i][j] != 0 && a[i][j] <= dist))
			return true;
		return false;
	}
	void dfs(vector<vector<int>> &a, int i, int j, int n, int dist = 1) {
		if (isNotSafe(a, i, j, n, dist))
			return;
		a[i][j] = dist;
		dfs(a, i - 1, j, n, dist + 1);
		dfs(a, i + 1, j, n, dist + 1);
		dfs(a, i, j - 1, n, dist + 1);
		dfs(a, i, j + 1, n, dist + 1);
	}

	int maxDistance(vector<vector<int>>& a) {
		int n = a.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					a[i][j] = 0;
					dfs(a, i, j, n);
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > 1)
					ans = max(ans, a[i][j] - 1);
			}
		}
		return ans;

	}
};