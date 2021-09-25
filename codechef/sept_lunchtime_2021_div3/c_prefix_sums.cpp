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
	while (t--)
	{
		int n;
		cin >> n;
		if (n % 4 == 0) {
			cout << "YES\n";
			cout << "1 4\n2 3\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}