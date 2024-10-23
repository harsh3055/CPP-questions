// this is the code to represent the graph which is unidirected and undirected or weighted graph 
// this is how we make the adjacency matrix for different type of the graph
#include<bits/stdc++.h>
#include<vector>
using namespace std;
// in case it is given that n is less than 10^3
cont int N = 1e3+10; 
// this is adjacency matrix
// global variable is already 0
int graph1[N][N];

// this is the adjacency list where there is V vector  which store the 
// the connected node as a list
vector<int> graph2[V];

// to store the weight of the node along with them in the adjacency list w
//  we can use the vector of pairs
vector<pair<int, int>>graph[N];


int main(){
	int V, E;
	cin>>V>>E;
	for(int i =0; i<m; ++i){
		int v1,v2,wt;
		cin>>v1>>v2>>wt;
		// if weight is given than in place of one we can assign
		//  the weight in the matrix

		// adjacency matrix
		// o(N^2) - space complexity(too much)
		// n = 10^5
		graph1[v1][v2]=1;
		graph1[v2][v1]= wt;


		// adjacency list if used to store the connected node of the vertex 
		// space complexity is O(V+E)
		// n = 10^5

		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
		// in case of the weighted graph we use to makw pait of the vertex in which one is node and the other onw in weight of the node
		graph[v1].push_back({v2, wt})
		// adhacency list
		// 



	}

}