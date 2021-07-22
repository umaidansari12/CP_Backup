#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int fib(int n)
{
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}

int calculateSum(int l, int r)
{
	// Using our deduced result
	int sum = 0;
	for (int i = l; i <= r; i++)
	{
		sum = ((sum % mod) + (fib(i) % mod)) % mod;
	}
	//int sum = ((fib(r + 2) % mod) - (fib(l + 1) % mod)) % mod;
	return sum;
}

// Driver code
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << calculateSum(l, r) << endl;

	}
	return 0;
}