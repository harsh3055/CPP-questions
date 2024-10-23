// we have to calculate the largest area of the rectangle in histogram
//push the element in the stack and if you find a smaller element then that is the boundry for the pre
//element so calculate its area
#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

int findLargest(vector<int>&nums){
	stack<pair<int,int>>st;
	int maxi = INT_MIN;
	st.push({nums[0],0});
	for(int i = 1 ; i< nums.size();i++){
		if(not st.empty() and st.top().first<nums[i])
		{
			int val = st.top().first;
			int ind = st.top().second;
			//cout<<val<<" "<<ind<<endl;
			st.pop();
			maxi = max(maxi, (i-ind+1)*val);
			st.push({nums[i],i});
			//cout<<maxi<<"h";
		}
			else{
			if(st.top().first>=nums[i])
				maxi = max(maxi, (i-st.top().second)*nums[i]);
		//	cout<<maxi<<"k";
			st.push({nums[i],i});
		}
		
	}
	return maxi;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
	int n; cin>>n;
	vector<int>nums(n);
	for(int i = 0; i< n; i++)
		cin>>nums[i];
	int count;
	count = findLargest(nums);
	cout<<count;
}