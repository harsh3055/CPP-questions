//length of the river using dfs
#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>>&graph,int i , int j, int &size){
	int v[5]= {-1,0,1,0,-1}; 
	int height = graph.size();
	int width  = graph[0].size();
	if((i>=0 && i<height) &&(j>=0 && j< width)){
		if(graph[i][j]==1){
			graph[i][j]=0;
			size++;
			for(int  k = 0 ; k<4 ;k++)
        	dfs(graph,i+v[k],j+v[k+1],size);
		}
	  }
    }


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>graph;
	vector<int>ans;
	for(int i = 0 ; i<n ; i++){
		vector<int>temp;
		for(int j =0 ; j< m; j++ ){
			int a; cin>>a;
			//cout<<a<<endl;
			temp.emplace_back(a);
		}
		graph.emplace_back(temp);

	}

	for(int y =0 ;y<n; ++y){
		for(int z = 0; z<m; ++z){
			int val = graph[y][z];
			if(val==1){
				int size =0;
				dfs(graph, y, z,size);
			 	ans.emplace_back(size);
			}
		}
	}
	
	for(int i = 0; i< ans.size(); i++)
		cout<<ans[i]<<"  ";
}
