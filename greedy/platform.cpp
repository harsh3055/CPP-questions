//minimum number of platform for the arrival and the diparture of the trains(gfg)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int platform(vector<int>&arr,vector<int>&dip){
	int n = arr.size();
	int j = 0;
	int count=0;
	for(int k = 0; k<n; k++){
		if(dip[j]<arr[k+1]){
			j++;
		}
		else
			count++;
	}
	return count;

}

int main(){
	vector<int>arr;
	vector<int>dip;

	int n; 
	cin>>n;

	for(int i = 0; i<n; i++){
		int a; 
		cin>>a;
		arr.push_back(a);
	}

	for(int i = 0; i<n; i++){
		int a; cin>>a;
		dip.push_back(a);
	}

	sort(arr.begin(),arr.end());
	sort(dip.begin(),dip.end());


	int count = platform(arr,dip);
	cout<<count;
}
