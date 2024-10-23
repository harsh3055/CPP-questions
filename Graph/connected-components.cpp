//using DFS for finding the components and the loop inside a graph
#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int N = 1e5 + 10;

vector<int>adj[N];
bool vis[N];// array for the visited node



bool dfs(int vertex, int parent) {
// take action on vertex after entering the vertex

	vis[vertex] = true;
	bool isloopexists = false;
	for (int child : adj[vertex]) {
		//take action on child before entering the child node

		if (vis[child] && child == parent) continue;
		if (vis[child]) return true; // means loop is present
		isloopexists |= dfs(child, vertex);
		//take action on child after exiting the child node
	}
// take action on vertex before exiting the vertex
	return isloopexists;
}

//O(V+E)
int main() {
	// taking input of the vertex and the edges
	int n, e;
	cin >> n >> e;

// making adjacency matrix of the graph
	for (int i = 0; i < e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	// calling the dfs function on vertex that is not visited to find the loops in the graph
	bool isloopexists = false;
	for (int i = 0 ; i < e; ++i) {
		if (vis[i]) continue;
		if (dfs(i, 0)) {
			isloopexists = true;
			break;
		}
	}
	cout << isloopexists << endl;
}

