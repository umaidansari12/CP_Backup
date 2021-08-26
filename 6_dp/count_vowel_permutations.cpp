class Solution {
public:
    int mod = 100000007;
    int solve(int n, string r)
    {
        if (r.size() == n)
        {
            return 1;
        }
        char ch = r[r.size() - 1];
        if (ch == 'a')
            return (solve(n, r + "e") % mod);
        else if (ch == 'e')
            return ((solve(n, r + "a") % mod) + (solve(n, r + "i") % mod)) % mod;
        else if (ch == 'i')
            return ((solve(n, r + "a") % mod) + (solve(n, r + "e") % mod) + (solve(n, r + "o") % mod) + (solve(n, r + "u") % mod)) % mod;
        else if (ch == 'o')
            return ((solve(n, r + "i") % mod) + (solve(n, r + "u") % mod)) % mod;
        else if (ch == 'u')
            return (solve(n, r + "a") % mod);
        return 0;
    }
    int countVowelPermutation(int n) {
        return ((solve(n, "a") % mod) + (solve(n, "e") % mod) + (solve(n, "i") % mod) + (solve(n, "o") % mod) + (solve(n, "u") % mod)) % mod;
    }
};