#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPalindrome(string s)
{
	string rev = s;
	reverse(s.begin(), s.end());
	return rev == s;
}

string longestPalin (string s) {
	// code here
	int ans = 0, n = s.size(), start = -1;
	for (int i = 0; i < n; i++)
	{
		string temp;
		for (int j = i; j < n; j++)
		{
			temp += s[j];
			//cout << temp << endl;
			if (isPalindrome(temp))
			{
				int n = temp.size();
				if (ans < n)
				{
					ans = n;
					start = i;
				}
			}
		}
	}
	return s.substr(start, ans);
}

int lengthOfLongestPalindromicSubstring(string s, int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string temp;
		for (int j = i; j < n; j++)
		{
			temp += s[j];
			//cout << temp << endl;
			if (isPalindrome(temp))
			{
				int n = temp.size();
				ans = max(ans, n);
			}
		}
	}
	return ans;
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
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << lengthOfLongestPalindromicSubstring(s, n) << endl;
	}


	return 0;
}