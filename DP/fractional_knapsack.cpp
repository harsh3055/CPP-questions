#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,va;
	cin>>n>>va;
	vector<int>val,weight;
	
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		val.push_back(a);
	}
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		weight.push_back(a);
	}

	for(int i = 0; i<n; i++){
		val[i]=val[i]/weight[i];
	}

	int i =0;
	int sum=0;
	while(i<n&&va>=0){
		if(va>weight[i]){
		sum+=val[i]*weight[i];
		va-=weight[i];
		i++;
	}
		else{
			sum+=va*val[i];
			i++;
	}
	}
	cout<<sum;
}