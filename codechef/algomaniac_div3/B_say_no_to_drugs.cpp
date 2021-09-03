#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	long long int n, mx = -1001, k, l, countDrugs = 0;
	cin >> n >> k >> l;
	long long int a[n] = {0};
	map<long long int, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		m[a[i]]++;
	}
	if (a[n - 1] == mx and m[a[n - 1]] == 1)
	{
		cout << "Yes\n";
		return;
	}
	if (k <= 0)
	{
		cout << "No\n";
		return;
	}
	/*while (countDrugs < l)
	{
		countDrugs += k;
		if ((a[n - 1] + countDrugs) > mx)
		{
			cout << "Yes\n";
			return;
		}
	}*/
	if ((l % k) == 0)
		countDrugs = (l / k) - 1;
	else
		countDrugs = (l / k);
	countDrugs *= k;
	if ((a[n - 1] + countDrugs) > mx)
	{
		cout << "Yes\n";
		return;
	}

	cout << "No\n";

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {

		solve();

	}


	return 0;
}