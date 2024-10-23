// diameter of the tree (generic tree)
// * first calculate the depth of each node wrt to any parent 
// * store the node with the highest depth
// * calling the dfs with  the node of highest depth and taking again the largest depth

#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int N = 1e5+10;

// this is for storing the connected vertex 
vector<int>g[N];
int depth[N];



void dfs(int vertex, int parent = -1){
// take action on vertex after entering the vertex
	for(int child : g[vertex]){
		//take action on child before entering the the child node
		if(child == parent) continue;
		// depth of the child is equal to the depth of the parent plus one
		depth[child] = depth[vertex]+1;

		dfs(child, vertex);

		//take action on child after exitiing the child node
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
		dfs(1);

		int mx_depth = -1;
		int mx_depth_node;
// we will store the node with the maximum depth 
		for(int i = 1; i<=n ; i++){
			if(mx_depth < depth[i]){
				mx_depth= depth[i];
				mx_depth_node = i;
			}
			depth[i]=0;
		}
// calling dfs on the node with the max depth 
		dfs(mx_depth_node);

// this will give you the diameter of the tree
		int depth_max=-1;
		for(int j = 1; j<=n ; j++){
			if(depth_max < depth[j]){
				depth_max = depth[j];
			
			}
		}
		cout<<depth_max;
}
