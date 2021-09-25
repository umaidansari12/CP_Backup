#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int SOD(long long int x) {
	long long int sum = 0;
	while (x) {
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long int l, r, cnt = 0;
		cin >> l >> r;
		long long int num = (r - l);
		double ans = num / (double)3;
		//cout << ans << endl;
		cnt = round(ans);
		cout << cnt << endl;
		// for (int i = l; i <= r; i++) {
		// 	if (SOD(i) % 3 == 0)
		// 		cnt++;
		// }
		// cout << cnt << endl;
	}

	return 0;
}