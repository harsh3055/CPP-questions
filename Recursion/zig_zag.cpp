#include<iostream>
#include<string>
using namespace std;


int dfs(string & s, int ind, int &count = 0 , int &count1 = 0, int &count2 = 0){
	if(ind>=s.size()){
		// cout<<ind;
		// cout<<s<<endl;
		return count+min(count2,count1);
	}

	if(s[ind] == '\'' and s[ind-1] !='/'){
		s[ind-1]= '/';
		dfs(s, ind+1,count+1, count1, count2);
	}

	else if(s[ind] == '/' and (s[ind-1] !='\'')){
		s[ind-1]='\'';
		dfs(s,ind+1,count,count1,count2+1);

		s[ind+1] = 'V';
		dfs(s,ind+1,count,count1+1,count2);
		
		// s[ind+1]='\'';
		// dfs(s,ind+1,count,count1,count2+1);
	}

	else if(s[ind] == 'V' and (s[ind-1] !='\'' or s[ind-1]!='V'))
		{
			s[ind-1] = '\'';
			dfs(s,ind+1,count+1,count1,count2);
		}
		else
	dfs(s,ind+1,count,count1,count2);
	

}
int main(){
	string s; cin>>s;
	int count = dfs(s,1);
	cout<<count;
	
}