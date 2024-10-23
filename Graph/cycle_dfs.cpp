// detect cycle in undirected graph using dfs
//time complexity O(N+2E)
//space complexity O(N)

#include<iostream>
#include<vector>
using namespace std;

dfs_cycle(int node,int parent,vector<int>adj[],vector<int>&visited){
	
	visited[node]=1;
	for(auto it:adj[node]){
		if(!visited[it]){
			if(dfs_cycle(it,node,adj,visited)==true) 
				return true;
		}
		else if(it!= parent) 
			return true;
	}
	return false;
	

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
	
	int n,e;
	cin>>n>>e;
	int a,b;
	vector<int>adj[n+1];
	vector<int>visited(n,0);
	for(int i =0; i<e; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
bool is_cycle=false;
for(int i =0; i<n ; i++){
	if(!visited[i])
	is_cycle=is_cycle || dfs_cycle(i,-1,adj,visited);
}
cout<<is_cycle;
	
}