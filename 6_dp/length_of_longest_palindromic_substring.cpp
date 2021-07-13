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

int longestPalindrome(string s)
{
	int n = s.size(), maxLength = 1;
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			maxLength = max(maxLength, 2);
		}
	}
	for (int k = 3; k <= n; k++)
	{
		for (int i = 0; i < (n - k + 1); i++)
		{
			int j = i + k - 1;
			if (s[i] == s[j] and dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				maxLength = max(maxLength, k);
			}
		}
	}
	return maxLength;
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
		cout << longestPalindrome(s) << endl;
	}


	return 0;
}