// we have to give output as two vector whose sum is a target vector

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void print(int a, int b, vector<vector<int>>nums){
	for(int i =0 ; i< nums.size(); i++){
		if(i==a||i==b){
			for(int j =0; j< nums[0].size(); j++)
				cout<<nums[i][j]<<" ";
			cout<<endl;
		}	
	}
}

void find_two_indices(vector<vector<int>>&nums,vector<int>&target, map<string,int>&mp){
string s;
	for(int i = 0; i<nums.size(); i++){
		for(int j =0; j<nums[0].size(); j++)
			s+=to_string(target[j]-nums[i][j]);
		if(mp.find(s)!=mp.end()){
			print(i,mp[s],nums);
	    	//mp.erase(s);
	    	break;
		}
		s="";
    }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n,m;
	cin>>n>>m;
	int a; 
	vector<vector<int>>nums;
	map<string,int>mp;
	for(int i =0; i<n; i++){
		string s;
		vector<int>temp;
		for(int j =0; j<m; j++){
			cin>>a;
			temp.emplace_back(a);
			s+=to_string(a);
		}
		mp[s]=i;
		nums.emplace_back(temp);
		temp.clear();
	}
	vector<int>target;
	for(int i =0; i<m; i++){
		cin>>a;
		target.emplace_back(a);
	}

	find_two_indices(nums,target,mp);
}