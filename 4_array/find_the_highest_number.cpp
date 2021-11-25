#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findPeakElement(vector<int>& a)
    {
        // Code here. first approach is to use linear  search and find the
        // maximum number out of it. This will take O(n) time while
        // traversing the array.
        int _max = a[0];
        for (int i = 0; i < a.size(); i++) {
            _max = max(a[i], _max);
        }
        return _max;
    }
};



// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        int ans = ob.findPeakElement(a);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends