//just make the j-i+1 or the window side to 2 for the number of the toys
// and just do the same as any other sliding window problem
#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;


int solve(string& s)
{
	unordered_map<char,int>mp;
	
	int z = s.size();
	int i=0,j=0,mx=INT_MIN,l;
	while(j<z){

        mp[s[j]]++;
        
		//if the number of toys in the map is equal to 2 then we just store the max of all the window size
		if(mp.size() == 2){
			l = j-i+1;
			mx = max(mx,l);
			
			
		}
		else{// if the size of the map gets greater than the required toys then just keep on subtracting the
		// the toys in the map until the size of the map gets equal to 2 
			while(mp.size()>2){
				mp[s[i]]--;
				if(mp[s[i]]==0){
					mp.erase(s[i]);
				}
				i++;
				
			}
		}
		
		j++;


	}
	return mx;


}

int main(){
string s;
cin>>s;
int ans = solve(s);
cout<<ans;
}