class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> inDegree(numCourses, 0);
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue <int> q;
        vector<int> topo;
        for (int node = 0; node < numCourses; node++)
        {
            if (inDegree[node] == 0)
            {
                q.push(node);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto neighbour : graph[node])
            {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        reverse(topo.begin(), topo.end());
        if (topo.size() == numCourses)
            return topo;
        return {};

    }
};

class Solution {
public:
    bool checkCycle(int node, vector<int> graph[], vector<bool>&vis, vector<bool>&rec)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour] and checkCycle(neighbour, graph, vis, rec))
                return true;
            else if (rec[neighbour])
                return true;
        }
        rec[node] = false;
        return false;
    }
    void topoSort(int node, vector<int> graph[], vector<bool>&vis, stack<int>&s )
    {
        vis[node] = true;
        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour])
            {
                topoSort(neighbour, graph, vis, s);
            }
        }
        s.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<bool> vis(numCourses, false), rec(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (checkCycle(i, graph, vis, rec))
                return {};
        }

        stack<int> s;
        fill(vis.begin(), vis.end(), false);
        vector<int> topo;
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                topoSort(i, graph, vis, s);
            }
        }
        if (s.size() != numCourses)
            return {};
        while (!s.empty())
        {
            topo.push_back(s.top());
            s.pop();
        }
        reverse(topo.begin(), topo.end());
        if (topo.size() == numCourses)
            return topo;
        return {};

    }
};