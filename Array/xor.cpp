// we have to find length of the sub array whose xor is equal to a given number  
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int>&A,int B){
unordered_map<int,int>mp;
int Xor =0;
int count = 0;
for(auto num: A){
	Xor= Xor^num;
	if(Xor == B) count++;
	if(mp.find(Xor^B)!=mp.end()){
		count+=mp[Xor^B];
	}
	mp[Xor]++;
}
return count;
}

int main(){

#ifndef ONLINE_JUDGE
freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif

	int n;
	cin>>n;
	int b;
	cin>>b;
	vector<int>arr;
	for(int i =0; i<n;i++){
		int a; 
		cin>>a;
		arr.emplace_back(a);
	}

	int ans = solve(arr,b);
	cout<<ans;
}