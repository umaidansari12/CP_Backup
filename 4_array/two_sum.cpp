#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
		// code here
		//time - O(N^2) space  - O(1)
		// for(int i=0;i<n;i++)
		// {
		//     for(int j=i+1;j<n;j++)
		//     {
		//         if((arr[i]+arr[j])==x)
		//         return true;
		//     }
		// }
		// return false
		//time - O(N) space  - O(N)
		//unordered_map<int,int> m;
		//for(int i=0;i<n;i++)
		//{
		//    if(m.find(x-arr[i])!=m.end())
		//    return true;
		//    m.insert(make_pair(arr[i],1));
		//}
		//return false;
		//time - O(NlogN) space  - O(1)
		sort(arr, arr + n);
		int i = 0, j = n - 1;
		while (i < j)
		{
			int sum = arr[i] + arr[j];
			if (sum == x)
				return true;
			else if (sum < x)
				i++;
			else
				j--;
		}
		return false;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.hasArrayTwoCandidates(arr, n, x);
		cout << (ans ? "Yes\n" : "No\n");
	}
	return 0;
}
// } Driver Code Ends