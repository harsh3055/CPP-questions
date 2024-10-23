//leght of the river and number of the island using dfs
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &graph, int i , int j,int & size){

int dir[5] = {-1,0,1,0,-1};
	int height = graph.size();
	int width = graph[0].size();

	if((i>=0 and i < width) and (j>=0 and j< height)){
	if(graph[i][j]==1){
		   graph[i][j] = 0;
			size++;
			for(int k = 0 ; k< 4; k++){
				dfs(graph, i+dir[k], j + dir[k+1],size);
			}
		}
	}
	
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n, m;
	cin>>n>>m;
	vector<vector<int>> graph;
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

int number_of_islands=0;
	for(int i = 0; i< n; i++){
		for(int j = 0; j< n; j++){
			if(graph[i][j]==1){
				number_of_islands++;
				int size =0;
				dfs(graph, i, j,size);
				ans.push_back(size);
			}
		}
	}
	for(auto it : ans)
	cout<<it<<" ";
	cout<<number_of_islands;
}