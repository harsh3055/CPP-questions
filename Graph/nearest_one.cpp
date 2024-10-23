// finding the distance of the nearest one in the
// matrix using bfs graph traversal;

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void nearest(vector<vector<int>>grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>>vis(n, vector<int>(m, 0));
	vector<vector<int>>dist(n, vector<int>(m, 0));
	queue<pair<pair<int, int>, int>>q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				q.push({{i, j}, 0});
				vis[i][j] = 1;
			}
			else
				vis[i][j] = 0;
		}
	}

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int steps = q.front().second;
		q.pop();
		dist[row][col] = steps;
		int dis[5] = { -1, 0, 1, 0, -1};
		for (int i = 0; i < 4; i++) {
			int new_x = row + dis[i];
			int new_y = col + dis[i + 1];
			if (new_x >= 0 and new_x<n and new_x >= 0 and new_y < n and vis[new_x][new_y] == 0)
			{
				vis[new_x][new_y] = 1;
				q.push({{new_x, new_y}, steps + 1});
			}
		}
	}
	for (auto it : dist) {
		for (auto val : it)
			cout << val << " ";
		cout << endl;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n, m;
	cin >> n >> m;
	int val;
	vector<vector<int>>grid;
	for (int i = 0; i < n; i++) {

		vector<int>temp;

		for (int j = 0; j < m; j++) {
			cin >> val;
			temp.emplace_back(val);

		}
		grid.emplace_back(temp);
	}
	nearest(grid);
	// for(auto col : ans){
	// 	for(auto row : col){
	// 		cout<<row<<" ";
	// 	}
	// 	cout<<endl;
}

