// depth first search in a tree(findinng height and depth of the tree)
// when vertex and edge is given 
#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int N = 1e5+10;

vector<int>g[N];
// array to calcuate the depth and height of the tree
int height[N], depth[N];


void dfs(int vertex, int parent = 0){
// take action on vertex after entering the vertex
	for(int child : g[vertex]){
		//take action on child before entering the child node

		if(child == parent) continue;
		depth[child] = depth[vertex]+1;
		dfs(child, vertex);

		//take action on child after exitiing the child node

	height[vertex] = max(height[vertex] , height[child]+1);
	}
// take action on vertex before exiting the vertex
}

int main(){
	int n;
	cin>>n;
// making adjacency matrix of the graph
	//every tree with n vertices has only n-1 edges 
	for(int i = 0; i<n-1;++i){
		int v1, v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	// calling dfs on the root node which dont have any parent
		dfs(1,0);

		for(int i = 0; i<=n ; i++)
			cout<<height[i]<<" "<<depth[i]<<endl;
	
}
