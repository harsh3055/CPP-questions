// dfs in tree and precomputation in tree

#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int N = 1e5 + 10;

// this is for storing the connected vertex
vector<int>g[N];
// array to calcuate the subtree sum and even number in that subtree of the tree
int subtree_sum[N], even_sum[N];


void dfs(int vertex, int parent = 0) {
// take action on vertex after entering the vertex
	if (vertex % 2 == 0)
		even_sum[vertex] += 1;

	subtree_sum[vertex] += vertex;

	for (int child : g[vertex]) {
		//take action on child before entering the the child node
		if (child == parent) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
		even_sum[vertex] += even_sum[child];
		//take action on child after exitiing the child node
	}
// take action on vertex before exiting the vertex
}

int main() {
	int n;
	cin >> n;
// making adjacency matrix of the graph
	//every tree with n vertices has only n-1 edges
	for (int i = 0; i < n - 1; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	// calling dfs on the root node which dont have any parent
	dfs(1);
	for (int i = 0; i <= n; i++)
		cout << subtree_sum[i] << " " << even_sum[i] << endl;

}
