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
		long long int x, _or = 0, ans = -1;
		cin >> x;
		bool flag = false;
		for (long long int i = 0; i <= x; i++) {
			if ((_or | i) <= x) {
				_or |= i;
			}
			else
			{
				//	cout << i << endl;
				flag = true;
				ans = i;
				break;
			}
		}
		if (!flag)
			cout << x + 1 << endl;
		else
			cout << ans << endl;
	}



	return 0;
}