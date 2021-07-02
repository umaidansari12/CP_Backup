#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int targetSum(int arr[], int s1, int i, int n, int sum)
{
	if (i == n)
	{
		if (sum == s1)
			return 1;
		else
			return 0;
	}
	return targetSum(arr, s1 + arr[i], i + 1, n, sum) + targetSum(arr, s1 - arr[i], i + 1, n, sum);
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
		int n, sum;
		cin >> n >> sum;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << targetSum(a, 0, 0, n, sum) << endl;
	}


	return 0;
}