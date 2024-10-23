// to find the total number of connected components

// time complexity O(N)+O(V+2E)
//space complexity O(N)
#include<iostream>
#include<vector>
using namespace std;


void dfs(int node, vector<int>&visited, vector<int>adj[]){
        visited[node]=1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }

   }

 int main(){
 	int count =0;
	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
	int n,m,a, b;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i = 0 ; i<m ; i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int>visited(n,0);
	for(int i =0; i< n; i++)
	{
		if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        cout<<count;

}
