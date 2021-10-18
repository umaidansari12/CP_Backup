#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {

        // Your code here
        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            ans = max(sum, ans);
            if (sum < 0)
                sum = 0;
        }
        return ans;

    }
    long long maxSubarraySumBrute(int arr[], int n) {

        // Your code here
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                res = max(res, sum);
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t; //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends