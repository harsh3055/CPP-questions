#include<iostream>
using namespace std;
#include<vector>


void solve(){
	long long int n,minimum,maximum;
	cin>>n;
	if(n%2!=0) {
		cout<<-1<<"\n";
		return;}
		
	if(n<4){
		cout<<-1<<"\n";
		return;}
		
	if(n%4==0 && n%6!=0)
	{
		maximum=n/4;
		long long k = n/6;
		minimum=k+1ll;
		cout<<minimum<<" "<<maximum<<"\n";
		return;
	}
	
	if(n%4!=0 && n%6==0){
		long long k = n/6;
		minimum=k;
		if(k%2!=0)
			k-=1;

		long long l=k/2;
		maximum = l*3+1;
		cout<<minimum<<" "<<maximum<<"\n";
		return;

	}

	if(n%4==0 && n%6==0){

		minimum = n/6;
		maximum = n/4;
		cout<<minimum<<" "<<maximum<<"\n";
		return;
	}

	if(n%2==0 && n%4!=0 && n%6!=0){
			long long k = n/4;
			maximum=k;
			k=k-1;
			minimum=(k/3)*2+k%3+1;
			cout<<minimum<<" "<<maximum<<"\n";
			return;
		}
}



int main(){
int t;
cin>>t;
while(t--)
	solve();

}