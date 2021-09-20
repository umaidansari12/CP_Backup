#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        // your code here
        int diff = INT_MAX, ans = 0;
        //we are taking every pair of elements and making their sum closest to zero
        //by taking absolute sum and making it near to zero
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (diff > abs(arr[i] + arr[j]))
                {
                    diff = abs(arr[i] + arr[j]);
                    ans = arr[i] + arr[j];
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends