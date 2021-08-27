class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        list<int> adj[n];
        for (auto edge : roads)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                unordered_set<int> a;
                for (auto neighbour : adj[i])
                    a.insert(neighbour);
                for (auto neighbour : adj[j])
                    a.insert(neighbour);
                ans = max(ans, (int)a.size());
            }
        }
        return ans;
    }
};

// above is wrong solution

