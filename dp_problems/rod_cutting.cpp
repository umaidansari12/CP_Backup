
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int helper(int n, int rod, int price[], int length[], vector<vector<int>>&dp)
    {
        if (n == 0)
            return 0;
        if (dp[n][rod] != -1)
            return dp[n][rod];
        if (length[n - 1] <= rod)
            return dp[n][rod] = max(price[n - 1] + helper(n, rod - length[n - 1], price, length, dp), helper(n - 1, rod, price, length, dp));
        else
            return dp[n][rod] = helper(n - 1, rod, price, length, dp);
    }
    int cutRod(int price[], int n) {
        //code here
        int length[n] = {0};
        for (int i = 0; i < n; i++)
            length[i] = i + 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(n, n, price, length, dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends