// cycle in graph using bfs in undirected graph
// time complexity O(N+2E)
//space of queue O(N)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect_cycle(int src,vector<int>adj[], vector<int>& visited){
	visited[src] =1;
	queue<pair<int,int>>q;
	q.push({src,-1});
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for(auto adjacentNode : adj[node]){
			if(!visited[adjacentNode]){
				visited[adjacentNode]=1;
				q.push({adjacentNode,node});
			}
			else if(parent!=adjacentNode){
		       return true;
	        }			
		}
		
	}
	return false;
}

int main(){

#ifndef ONLINE_JUDGE
freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif

	int n, m, a,b;
	cin>>n>>m;
	bool cycle;
	vector<int>adj[n+1];
	vector<int>visited(n,0);
	for(int i =0; i<m; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	cout<<detect_cycle(1,adj,visited);
	

}