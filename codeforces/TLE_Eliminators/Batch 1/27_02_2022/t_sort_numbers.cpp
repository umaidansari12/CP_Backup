#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin>>t;
	while (t--) {
		int a[3] = {0}, b[3] = {0};
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
			b[i] = a[i];
		}

		sort(a, a + 3);

		for (int i = 0; i < 3; i++) {
			cout << a[i] << "\n";
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			cout << b[i] << "\n";
		}

	}


	return 0;
}