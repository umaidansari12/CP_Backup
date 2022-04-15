#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int numofsubset(int arr[], int n)
    {
        // Your code goes here
        sort(arr, arr + n);
        int cnt = 0, ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if ((arr[i] + 1) == arr[i + 1])
                cnt++;
            else
            {
                ans++;
                cnt = 0;
            }
        }
        return ans + 1;
    }
};

// { Driver Code Starts.
// Driven Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.numofsubset(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends