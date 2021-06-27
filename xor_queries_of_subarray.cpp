class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> res;
		for (int i = 0; i < queries.size(); i++)
		{
			int xr = 0;
			for (int j = queries[i][0]; j <= queries[i][1]; j++)
			{
				xr ^= arr[j];
			}
			res.push_back(xr);
		}
		return res;
	}
};

class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		int n = arr.size();
		vector<int> res, prefix(n, 0);
		prefix[0] = arr[0];
		for (int i = 1; i < n; i++)
		{
			prefix[i] = prefix[i - 1] ^ arr[i];
		}
		for (int i = 0; i < queries.size(); i++)
		{
			int l = queries[i][0], r = queries[i][1];
			if (l == 0)
				res.push_back(prefix[r]);
			else
				res.push_back(prefix[r]^prefix[l - 1]);
		}
		return res;


	}
}; o