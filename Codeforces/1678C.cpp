#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; 
	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
		vector<int>per(n,0);

		for(int i=0;i<n;i++){
			cin>>per[i];
		}

		vector<pair<int,int>>anc;
		for(int a = 0; a<n-3;a++){
			for(int c=a+2;c<n-1;c++){
			if(per[a]<per[c])
				anc.emplace_back(make_pair(a,c));
			}
		}
		vector<pair<int,int>>bnd;
		for(int b = 0; b<n-2;b++){
			for(int d=b+2;d<n;d++){
			if(per[b]>per[d])
				bnd.emplace_back(make_pair(b,d));

			}
		}
		

		int res =0;
		for(auto &fp :anc){
			for(auto &sp :bnd)
			{
				if((fp.first<sp.first)&&(sp.first<fp.second)&&(fp.second<sp.second))
					res++;
			}
		}
		cout<<res<<"\n";
	}
}
