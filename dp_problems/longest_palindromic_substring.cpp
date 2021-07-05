#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	bool isPalindrome(string s)
	{
		string rev = s;
		reverse(s.begin(), s.end());
		return rev == s;
	}

	string longestPalindrome(string s)
	{
		/*for (int i = 0; i < s.length(); i++)
		{
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[i] == s[j])
			{
				int k = i, m = j;
				while (k < m)
				{
					if (s[k] != s[m])
						break;
				}
			}
		}
		}*/
		int mx = 0, start = -1;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				//
				int flag = 1;
				for (int k = 0; k < (j - i + 1) / 2; k++)
				{
					if (s[i + k] != s[j - k])
						flag = 0;
				}
				if (flag && (j - i + 1) > mx)
				{
					//cout << i << " " << j << endl;
					start = i;
					mx = j - i + 1;
				}
			}
		}
		for (int i = start; i <= (start + mx) - 1; i++)
			cout << s[i];
		cout << endl;
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
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string S; cin >> S;

		Solution ob;
		cout << ob.longestPalin (S) << endl;
	}
}
// Contributed By: Pranay Bansal
// } Driver Code Ends