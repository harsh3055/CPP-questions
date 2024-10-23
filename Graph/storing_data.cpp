#include<iostream>
using namespace std;
// n is total number of vertex
//m is the total number of edges 

// matrix representation of undirected graphs 
// space N*M
int main(){
	int n, m; 
	cin>>n>>m;
	int adj[n+1][m+1];
	for(int i = 0 ; i<m; i++)
	{
		int v, u;
		cin>>v>>u;
		adj[v][u] =1;
	}
}

//vector representation
// space 2*E
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i = 0; i<m ;i++){
		int a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
}


// how to store the weightes graph in vector
// use pair to store the neighbouring vertex with the weight

int main(){
	int n,m; 
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for(int i = 0 ; i<m; i++){
		int v1, v2, w;
		cin>>v1>>v2>>w;
		adj[v1].emplace_back({v2,w});
		adj[v2].emplace_back({v1.w});
	}
}