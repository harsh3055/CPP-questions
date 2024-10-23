#include<iostream>
using namespace std;
#include<vector>
#include <map>
#include<numeric>

vector<long long>nums;
map<long long,long long>mp;
long new_full;
long prev_sum;
long sum;


int solve(){
	int i,j;
	long k;
	cin>>i;

	if(i==1){
		cin>>j>>k;
		if(mp.find(j)!=mp.end()){
			if(!prev_sum)
			sum = sum+k-mp[j];
	
		else
			sum= prev_sum+k-mp[j];

			return sum;
		}
		else{

		if(!prev_sum){
			sum = nums.size()*new_full+k-new_full;
			prev_sum=sum;
		}
		else
			sum = prev_sum+k-new_full;

			mp[j]=k;
			prev_sum=sum;
			return sum;
		}

	}
	if(i==2){
		cin>>j;
		new_full=j;
		sum = nums.size()*j;
		prev_sum=0;
		mp.clear();
	
		return sum;
	}

}



int main(){
	long long q,n;
	cin>>n>>q;
	
	for(int i =0,k;i<n;i++){
		cin>>k;
		nums.emplace_back(k);
		}

	for(int i=1;i<=n;i++)
		mp[i]=nums[i-1];

	sum = accumulate(nums.begin(), nums.end(), 0);

		while(q--){
			cout<<solve()<<"\n";
			
		}

}