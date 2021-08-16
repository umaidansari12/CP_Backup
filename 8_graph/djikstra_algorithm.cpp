#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int dist;
	int node;
	Node(int dist, int node)
	{
		this->dist = dist;
		this->node = node;
	}
};

void djikstraAlgorithm(vector<Node> adj[], int n, int src, int dest)
{
	//pair<int,int> -> (distance,destination); priority queue(min heap)
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair<int, int>>> p;
	vector<int> distTo(n + 1, INT_MAX);
	distTo[src] = 0;
	p.push({0, src});
	while (!p.empty()) {
		int distToNode = p.top().first;// taking distance of the current node from the source
		int currentNode = p.top().second;//taking current minimum node out of the priority queue(min heap)
		p.pop();
		for (auto i : adj[currentNode])// traversing neighbours of the current node
		{
			//taking next node
			int next = i.node;
			// taking the weight of the current neighbour node
			int nextDist = i.dist;
			// checking if the distance of the next node reachable is greater than from the current node (distance from src where it has come) + weight of the current node
			if (distTo[next] > nextDist + distTo[currentNode])
			{
				distTo[next] = nextDist + distTo[currentNode];
				p.push({distTo[next], next});
			}
		}
	}
	for (auto i : distTo)
		cout << i << " ";
	cout << '\n';
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, e, src, wt, dest;
		cin >> n >> e;
		//creating a weighted graph with distance as first element and node as second element
		vector<Node> adj[n + 1];
		//vector<pair<int,int>> adj[n+1];

		//creating a weighted graph having e edges
		for (int i = 0; i < e; i++)
		{
			cin >> src >> dest >> wt;
			Node s(wt, dest);
			Node d(wt, src);
			adj[src].push_back(s);
			adj[dest].push_back(d);
		}
		cin >> src >> dest;
		// for (int i = 1; i <= n; i++)
		// {
		// 	cout << i << " : ";
		// 	for (auto j : adj[i])
		// 	{
		// 		cout << "(" << j.dist << " " << j.node << "),";
		// 	}
		// 	cout << '\n';
		// }
		djikstraAlgorithm(adj, n, src, dest);
	}


	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}

	cin >> source;

	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths;

	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)

	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}

	}

	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";

	return 0;
}

*/