#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V + 1, INT_MAX); //to store the minimum edge weight that is coming to that node
        vector<int> parent(V + 1, -1); //parent - child relationship constructed using the parent array
        vector<bool> mst(V + 1, false); //mst array which tells whether the node is part of the mst or not if false not a part otherwise true that is a part of mst

        key[0] = 0; //it takes 0 edge weight cost to reach node 0 or start from node 0 to make it mst
        parent[0] = -1; //0 is the root element in the tree and its parent is 0
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair<int, int>>> p;
        p.push({0, 0});
        while (!p.empty()) // we need to include only (n-1) edges into our mst so we are running loop from 0 to n-1 not n
        {
            int currVertex = p.top().second;
            int weight = p.top().first;
            p.pop();

            // marking true to make the node which has minimum edge
            mst[currVertex] = true;
            //traversing the adjacent of current node and placing it in the key which has lower edge cost to reach
            //traversing the adjacent of current node and check if any adjacent node is reachable in lower edge cost as previous
            for (auto neighbour : adj[currVertex])
            {
                int node = neighbour[0];
                int weight = neighbour[1];
                //if the adjacent node is not a part of mst and it is reachable in lower edge cost then update edge cost in key and also mark it as a child of currVertex because it is reached at that cost from currVertex
                if (mst[node] == false and weight < key[node])
                {
                    key[node] = weight;
                    parent[node] = currVertex;
                    p.push({key[node], node});
                }
            }
        }
        int sum = 0;
        for (int i = 1; i <= V; i++) //calculating edge weights
        {
            if (key[i] != INT_MAX)
            {
                sum += key[i];
            }
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends