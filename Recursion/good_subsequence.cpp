// good sequence means alternating positive and negative numbers
// we have to reutn the longest subsequence with some sum

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void maxsum( vector<int>&arr, int n , int ind, bool &isnegative,int sum,priority_queue<pair<int,int>>&ans,int count=0){

	if(ind>=n) 
	{
		ans.push({count,sum});
		return;
	}

	if(isnegative and arr[ind]>0)
	{
		isnegative = false;
		//cout<<"l";
		count++;
		maxsum(arr, n,  ind+1,isnegative,sum+arr[ind],ans,count);
		count--;
		isnegative = true;
		maxsum(arr, n,ind+1,isnegative,sum,ans,count);
	}
	if(!isnegative and arr[ind]<0)
	{
		isnegative = true;
		//cout<<"t";
		count++;
		maxsum(arr, n,ind+1, isnegative,sum+arr[ind],ans,count);
		isnegative = false;
		count--;
		maxsum(arr, n,ind+1, isnegative,sum,ans,count);
	}
	else
		maxsum(arr, n,ind+1, isnegative,sum,ans,count);
}

int main(){
	int n; cin>>n;
	vector<int>arr(n);
	priority_queue<pair<int,int>>ans;
    bool negative ;
	for(int i = 0 ; i< n; i++)
		cin>>arr[i];
	if(arr[0]>0)
	negative = true;
	int sum = 0;

	maxsum(arr, n, 0, negative, sum,ans);
	
	cout<<ans.top().first<<" "<<ans.top().second<<endl;
	//cout<<*max_element(ans.begin(), ans.end());


}