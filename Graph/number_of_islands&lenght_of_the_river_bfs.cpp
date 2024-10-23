//number of island using bfs and length of the river too

#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int bfs(vector<vector<int>>&graph , int i , int j,int size,int dir[5]){

	
	int height = graph.size();
	int width= graph[0].size();
	queue<pair<int,int>>q;
	q.push({i,j});
	graph[i][j]=0;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i  = 0; i< 4; i++){
			int newrow= x+dir[i];
			int newcol = y+dir[i+1];
			if((newrow>=0 and newrow<height) and (newcol >=0 and newcol < width)){
				if(graph[newrow][newcol]==1){
					graph[newrow][newcol] = 0;
					size++;
					q.push({newrow,newcol});
			    }
		    }

	    }
    }
return size;
}

int main(){
	int n, m;
	cin>>n>>m;
	int dir[5] = {-1, 0, 1, 0, -1};
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
int size;
int number_of_islands=0;
	for(int i = 0; i< n; i++){
		for(int j = 0; j< m; j++){
			if(graph[i][j]==1){
				size = 1;
				number_of_islands++;
				size = bfs(graph, i, j,size,dir);
				//cout<<size;
				ans.push_back(size);
			}
			
		}
	}
	for(auto it : ans)
		cout<<it<<" ";
	cout<<"\n";
	cout<<number_of_islands;
}