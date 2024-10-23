#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

// reversing a string using recursion
void rev(string& str,int i)
{
	int n = str.size();
if(i>=str.size()/2)
	return;
else
	swap(str[i],str[n-i-1]);
rev(str,i+1);
}

// printing the nth fibonaci number
int fib(int n,vector<int>&dp){
	
	int last,secondLast;
	if(dp[n]==-1) {
	if(n==1)
		return 1;
	else if(n==0)
		return 0;

	last = fib(n-1,dp);
	secondLast= fib(n-2,dp);
	return dp[n]=last+secondLast;
}
else
 return dp[n];
}

// recursive funstion to print all the combination
void recur(int arr[],vector<int>& perm,int i,int n){

	if(i==n)
	{
		if(perm.size()==4){
			for(int num: perm)
				cout<<num;
			cout<<endl;
			return;
	}
	else return;
	}
    
	perm.push_back(arr[i]);
	recur(arr,perm,i+1,n);
	perm.pop_back();
	recur(arr,perm,i+1,n);
	
}

int main(){
vector<int>dp(10);
fill(dp.begin(),dp.end(),-1);
	int n;
	vector<int>perm;
	fill(perm.begin(),perm.end(),-1);
	cin>>n;
	int arr[n];
	for(int i = 0; i< n; i++){
		cin>>arr[i];
	}
	recur(arr,perm,0,n);

// 	for(int t=0; t<10;t++)
// cout<<fib(t,dp)<<endl;,
 // string name= "harsh";
 // rev(name,0);
 // cout<<name;
}
