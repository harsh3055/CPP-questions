// breath first search in graphs 
// we need a queue
// we need a adjacency list of size vertices+1
// we need a visited list
// space complexity is O(3N)
// time complexity is O(N)+O(2E)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> breath_first_search(vector<int>adj[],vector<int>&visited){
	queue<int>q;
	vector<int>bfs;
	q.push(3);
	visited[3]=1;
	//o(N)
	while(!q.empty()){
		int n = q.size();
		int node = q.front();
		q.pop();
		bfs.push_back(node);
		//O(2E)
		for(auto it: adj[node]){
			if(!visited[it]){
				visited[it]=1;
				q.push(it);
			}
		}
	}
	return bfs;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	
	int n,m; 
	cin>>n>>m;
	int v1, v2;
	vector<int>visited(n,0);
	vector<int>adj[n+1];
	for(int i = 0 ; i<m; i++){
		
		cin>>v1>>v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	//memset(visited, 0, sizeof(visited));
	vector<int>breath = breath_first_search(adj,visited);
	for(auto it: breath)
		cout<<it<<endl;
	
}
