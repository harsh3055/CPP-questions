//depth first search based on depth
//time complexity O(2E)+O(N)
// space complexity O(N)

#include<iostream>
#include<vector>
using namespace std;
void depth_first_search(vector<int>adj[], vector<int>&visited, int node, vector<int>& bfs) {
	visited[node] = 1;
	bfs.push_back(node);
	for (auto it : adj[node]) {
		if (!visited[it])
			depth_first_search(adj, visited, it, bfs);

	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	int n, m, a, b;
	cin >> n >> m;
	vector<int>adj[n + 1];
	for (int i = 0 ; i < m ; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int>visited(n, 0);
	vector<int>bfs;
	depth_first_search(adj, visited, 0, bfs);
	for (auto it : bfs)
		cout << it << endl;
}