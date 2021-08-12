#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int solve2() {
	long long int n, p, k, cnt = 1;
	cin >> n >> p >> k;
	//ll a[n];
	map<ll, ll> m;
	for (long long int i = 0; i < n; i++)
		m[i] = i;
	bool flag = false;
	for (long long int i = 0; i < k; i++)
	{
		//for (long long int j = 0; j < n; j++)
		for (auto j : m)
		{
			//if ((a[j] % k) == i and a[j] == p)
			if ((j.second % k) == i and j.second == p)
			{
				//return cnt;
				flag = true;
				break;
			}
			//else if ((a[j] % k) == i)
			else if ((j.second % k) == i)
				cnt++;
		}
		if (flag)
			break;
	}
	return cnt;
}

long long int solve3() {
	long long int n, p, k, cnt = 0, key = -1;
	cin >> n >> p >> k;
	map<ll, vector<ll>> m;
	for (long long int i = 0; i < n; i++)
	{
		m[i % k].push_back(i);
		if (i == p)
		{
			key = i % k;

		}
	}

	for (auto i : m)
	{
		if (i.first == key)
		{
			for (auto j : i.second)
			{
				if (j == p)
				{
					return cnt + 1;
				}
				cnt++;
			}
		}
		cnt += i.second.size();
	}


	// bool flag = false;
	// for (long long int i = 0; i < k; i++)
	// {
	// 	//for (long long int j = 0; j < n; j++)
	// 	for (auto j : m)
	// 	{
	// 		//if ((a[j] % k) == i and a[j] == p)
	// 		if ((j.second % k) == i and j.second == p)
	// 		{
	// 			//return cnt;
	// 			flag = true;
	// 			break;
	// 		}
	// 		//else if ((a[j] % k) == i)
	// 		else if ((j.second % k) == i)
	// 			cnt++;
	// 	}
	// 	if (flag)
	// 		break;
	// }
	return cnt;
}

long long int solve1() {
	long long int n, p, k, cnt = 0, key = -1;
	cin >> n >> p >> k;
	//map<ll, vector<ll>> m;
	key = p % k;
	for (long long int i = 0; i < n; i++)
	{
		if ((i % k) < key)
			cnt++;
		if ((i % k) == key and i <= p)
		{
			cnt++;
		}
	}

	return cnt;

}



ll solve() {
	ll n, p, k, cnt = 1;
	cin >> n >> p >> k;

	ll a[n];
	for (ll i = 0; i < n; i++)
		a[i] = i;
	for (ll i = 0; i < k; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if ((a[j] % k) == i and a[j] == p)
			{
				return cnt;
			}
			else if ((a[j] % k) == i)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cout << solve1() << '\n';
	}

	return 0;
}