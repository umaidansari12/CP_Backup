#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Rainfall {
public:
	int start, end, rain;
};

vector<int> countLocations(vector<Rainfall> &rainfall, int n, vector<pair<int, int> > &queries, int q, int k, int max_ending) {
	vector<int> rains(max_ending + 2, 0);
	for (int i = 0; i < n; i++) {
		rains[rainfall[i].start] += rainfall[i].rain;
		rains[rainfall[i].end + 1] -= rainfall[i].rain;
	}
	for (int i = 1; i <= max_ending; i++) {
		rains[i] += rains[i - 1];
	}

	vector<int> res;
	for (int i = 0; i < q; i++) {
		int count = 0;
		for (int j = queries[i].first; j <= queries[i].second; j++) {
			if (rains[j] >= k)
				count++;
		}
		res.push_back(count);
	}
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, q, k, max_ending = 0;
		cin >> n >> q >> k;
		vector<Rainfall> rainfall(n);
		for (int i = 0; i < n; i++) {
			cin >> rainfall[i].start >> rainfall[i].end >> rainfall[i].rain;
			cout << rainfall[i].start << ", " << rainfall[i].end << ", " << rainfall[i].rain << endl;
			max_ending = max(max_ending, rainfall[i].end);
		}
		vector<pair<int, int>> queries(q);
		for (int i = 0; i < q; i++) {
			cin >> queries[i].first >> queries[i].second;
		}
		vector<int> result = countLocations(rainfall, n, queries, q, k, max_ending);
		for (auto i : result) {
			cout << i << " ";
		}
		cout << endl;
	}


	return 0;
}