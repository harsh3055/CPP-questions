// return the string of all possible path from 00 to n-1n-1 
//recursion and backtracking
// time complexity is O(4^(n*m))
// space complexity is O(n*m)

#include<iostream>
#include<vector>
using namespace std;

class solution{
public:
	void solve(int i, int j, vector<vector<int>>&m, int n,vector<string>&ans,string move, vector<vector<int>>&vis,int di[],int dj[]){
		if(i==n-1&&j=n-1){
			ans.emplace_back(move);
			return;
		}
		string dir="DLUR";
		for(int ind = 0; ind<4; i++){
			int nexti = i+di[ind];
			int nextj = j+dj[ind];
			if(nexti>=0&&nextj>=0&&nexti<n&&nextj<n&&!vis[nexti][nextj]&&m[nexti][nextj]==1){
				vis[i][j]=1;
				solve(nexti,nextj,m,n,ans, move+dir[ind],vis,di,dj);
				vis[i][j]=0;
			}
		}
	}

	vector<string> findpaths(vector<vector<int>>&m,int n){
		vector<string>ans;
		vector<vector<int>>vis(n,vector<int>(n,0));
		int di[]={1,0,0,-1};
		int dj[]={0,-1,1,0};
		if(m[0][0]==1){
			solve(0,0,m,n,ans,"",vis,di,dj);
		}
	}
};