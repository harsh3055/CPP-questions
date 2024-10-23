//to print sum of all the subsets and return the ans in vector
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helper(vector<int>&nums,int i, int sum,vector<int>&ans){
	if(i>=nums.size()){
		ans.push_back(sum);
		return;
	}
	helper(nums,i+1,sum+nums[i],ans);
	helper(nums,i+1,sum,ans);
}

int main(){

	int n; cin>>n;
	vector<int>nums;
	for(int i = 0; i<n;i++){
		int a; cin>>a;
		nums.emplace_back(a);
	}
	vector<int>ans;
	helper(nums,0,0,ans);
	sort(ans.begin(),ans.end());
	for(int num: ans)
		cout<<num;
}