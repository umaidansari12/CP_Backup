#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        // Your code goes here
        int n = arr.size();
        vector<vector<int>> res;
        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        int sum = arr[i] + arr[j] + arr[k] + arr[l];
                        if (sum == K)
                        {
                            vector<int> r;
                            r.push_back(arr[i]);
                            r.push_back(arr[j]);
                            r.push_back(arr[k]);
                            r.push_back(arr[l]);
                            sort(r.begin(), r.end());
                            s.insert(r);
                        }
                    }
                }
            }
        }
        for (auto i : s)
            res.push_back(i);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends