#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		cout << min(x / 2, y) << endl;
	}


	return 0;
}