// finding the lowest commman ancestor of the two node in a tree
// if tree is given in the form of vertex and edge
#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int N = 1e5 + 10;

vector<int>g[N];
int parent[N];// to store the parent of the vertex

// here we are using dfs to store the parent of each node in the parent array
void dfs(int vertex, int par = -1) {
	parent[vertex] = par; // storing the parent of the vertex
	for (int child : g[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);
	}
}

// function to take the path of any vertex to the root node
vector<int> path(int v) {
	vector<int>ans;
	while (v != -1)
	{
		ans.push_back(v);
		// we are making the vertic equal to parent to track the parent of all the vertices
		v = parent[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
// to store the parent of each node of the tree in the partent array
	dfs(1);

	int x, y;
	cin >> x >> y;
// we have two node vector of the parent
	vector<int>path_x = path(x);
	vector<int>path_y = path(y);


	// for(int i : path_x)
	// 	cout<<i<<" ";

	int min_length = min(path_x.size(), path_y.size());
	int lca = -1;
	for (int i = 0 ; i < min_length; ++i) {
		if (path_x[i] == path_y[i]) {
			lca = path_x[i];
		}
		else {
			break;
		}
	}
	cout << lca << endl;
}