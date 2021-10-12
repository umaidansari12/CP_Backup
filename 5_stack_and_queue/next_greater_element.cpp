#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
	//Function to find the next greater element for each element of the array.
	vector<long long> nextLargerElement(vector<long long> arr, int n) {
		// Your code here
		vector<long long int> res(n, 0);
		stack<int> s;
		s.push(0);
		for (int i = 1; i < n; i++) {
			if (arr[s.top()] > arr[i])
				s.push(i);
			else {
				while (!s.empty() and arr[s.top()] < arr[i])
				{
					res[s.top()] = arr[i];
					s.pop();
				}
				s.push(i);
			}
		}
		while (!s.empty()) {
			res[s.top()] = -1;
			s.pop();
		}
		return res;
	}
	vector<long long> nextLargerElement(vector<long long> a, int n) {
		// Your code here
		stack<long long> s;
		vector<long long> r;
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && a[i] >= s.top())
				s.pop();
			if (s.size() == 0)
				r.push_back(-1);
			else
				r.push_back(s.top());
			s.push(a[i]);
		}
		reverse(r.begin(), r.end());
		return r;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		vector<long long> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		Solution obj;
		vector <long long> res = obj.nextLargerElement(arr, n);
		for (long long i : res) cout << i << " ";
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends