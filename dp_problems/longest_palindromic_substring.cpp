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