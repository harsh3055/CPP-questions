// to find the largest sub array whose sum is equal to 0
// here we start summing the element if the at some point we find that the sum is alreadu present in the map
// then we found out the subarray withh the sum 0;
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        mp.insert({0,-1});
        
        int sum=0,fans=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(mp.find(sum)==mp.end())
                mp.insert({sum,i});
            
            else fans=max(fans,i-mp[sum]);
        }
        
        return fans;
    }

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif

	int n;
	cin>>n;
	vector<int>arr;
	int i = 0,j = 0;

for(int i= 0; i<n; i++){
	int a;
	cin>>a;
	arr.push_back(a);
}
 cout<<maxLen(arr,n)<<endl;
}