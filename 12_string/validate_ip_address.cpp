#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	string validIPAddress(string IP) {
		regex v4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
		if (regex_match(IP, v4))
			return "IPv4";
		//regex v6("((([0-9a-fA-F]){1-4})\\:){7}([0-9a-fA-F]){1-4}");
		regex v6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
		if (regex_match(IP, v6))
			return "IPv6";
		return "Neither";
	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		Solution ob;
		cout << ob.validIPAddress(s) << endl;
	}

	return 0;
}