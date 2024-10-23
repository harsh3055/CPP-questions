// finding the number of subset or subsequence with the target sum 
#include<iostream>
#include<vector>
using namespace std;


void findsub(vector<int>&arr,int target, int& count, int ind)
{
	
	if(ind>=arr.size())
	{
		if(target==0)
			count++;
		return;
	}
	
		findsub(arr, target-arr[ind], count, ind+1);
		
	   findsub(arr,target,count,ind+1);
}
int main(){
	int n ; cin>>n;
	int target; cin>>target;
	vector<int>arr(n);
	for(int i = 0; i< n; i++)
		cin>>arr[i];

	int count =0; 
	
	findsub(arr,target,count,0);
	cout<<count;
}