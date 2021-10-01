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
		int n;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		int max_and = 0;
		for (int i = 0; i < n; i++) {
			int _and = a[i];
			for (int j = i; j < n; j++) {
				_and = _and & a[j];
				if (_and > 0)
					max_and = max(max_and, j - i + 1);
			}
		}
		cout << max_and << endl;
	}
	return 0;
}