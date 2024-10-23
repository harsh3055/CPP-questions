#include<iostream>
#include<vector>
#include <queue>
using namespace std;



bool check(int i , int j, vector<vector<int>>&grid, vector<vector<int>>& vis) {
	int row = grid[0].size();
	int col = grid.size();
	if (i >= 0 and i<row and j >= 0 and j < col and vis[i][j] != 1)
		return true;
	else
		return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>>grid(n, vector<int>(m));

	vector<vector<int>>vis(n, vector<int>(m, 0));
	vector<vector<int>>dis(n, vector<int>(m, 0));
	queue<pair<pair<int, int>, int>>q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0;  j < m; j++) {
			if (grid[i][j] == 1) {
				q.push({{i, j}, 0});
				vis[i][j] = 1;
			}
			else {
				vis[i][j] = 0;
			}
		}
	}

	int dir[5] = { -1, 0, 1, 0, -1};

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int steps = q.front().second;
		dis[x][y] = steps;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dir[i];
			int new_y = y + dir[i + 1];

			if (check(new_x, new_y , grid, vis)) {
				vis[new_x][new_y] = 1;
				q.push({{new_x, new_y}, steps + 1});
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0;  j < m; j++) {
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}

}

