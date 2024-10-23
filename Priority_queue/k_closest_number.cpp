// we have to find the k closest number to a givern number in the array
// for that we are using the abs diff in the heap
// we are using maxh to pop the element having greater diff
// here are finding the sum between tow smallest number
#include<iostream>
#include <vector>
using namespace std;
#include<queue>

int kthsmallestnumber(vector<int>&nums,int k)
{
	priority_queue<int>pq;
	for(int i = 0; i< nums.size(); i++){
		pq.push(nums[i]);
		while(pq.size()>k)
			pq.pop();
	}
	return pq.top();
}
int main(){
	int n; cin>>n;
	int k ; cin>>k;
	int x; cin>>x;
	vector<int>ans;
	vector<int>nums(n);
	for(auto &num : nums)
		cin>>num;

	// priority_queue<pair<int,int>>maxh;

	// for(auto val : nums){
	// 	maxh.push({abs(val-x),val});
	// 	if(maxh.size()>k)
	// 		maxh.pop();
	// }
	// while(maxh.size()>0){
	// 	cout<<maxh.top().second<<endl;
	// 	maxh.pop();
	// }

	int firstsmall = kthsmallestnumber(nums,k);
	int secondsmall = kthsmallestnumber(nums,x);
	int sum = 0;
	for(auto num:nums)
		if(firstsmall<num&&num<secondsmall)
			sum+=num;

	cout<<sum;
}