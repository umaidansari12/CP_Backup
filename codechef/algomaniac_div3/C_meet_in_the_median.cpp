#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int idx, int &median, vector<int> &a, int n, int k, vector<int> &r, vector<int>&res)
{
	if (idx > n or r.size() > k)
		return;
	if (idx == n and r.size() == k)
	{
		vector<int> temp(r);
		sort(temp.begin(), temp.end());
		if (median < temp[(k / 2)])
		{
			res = r;
			median = temp[(k / 2)];
			return;
		}
	}
	r.push_back(a[idx]);
	solve(idx + 1, median, a, n, k, r, res);
	r.pop_back();
	solve(idx + 1, median, a, n, k, r, res);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k, median = 0;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> res;
		vector<int> r;
		solve(0, median, a, n, k, r, res);
		cout << median << endl;
		for (auto i : res)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}