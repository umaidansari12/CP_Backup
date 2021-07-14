#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int n, k, ans = 0;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	/*
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0 and arr[i] >= arr[k - 1])
			ans++;
	}
	*/
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << solve() << endl;


	return 0;
}