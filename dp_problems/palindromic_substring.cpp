class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            count++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                count++;
            }
        }
        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < (n - k + 1); i++)
            {
                int j = (i + k - 1);
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};