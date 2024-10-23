#include<bits/stdc++.h>
using namespace std;
const int N = 2510;

int dp[10][10];

int func(int ind, int amount, vector<int>& coins){
	// doing the conditon check on the variable arguments 
	if(amount==0) return 1;
	if(ind < 0) return 0;
	//checking if the value is already calculated prev
	if(dp[ind][amount]!= -1) return dp[ind][amount];

	int ways = 0;

for(int coin_amount = 0; coin_amount <=amount; coin_amount += coins[ind]){
// if at the end if amount gets equal to 0 then the function return 1 which gets added to the no of ways 
ways+=func(ind-1,amount-coin_amount,coins);

 }
        
return dp[ind][amount] = ways;

}


int coinChange(vector<int>&coins ,int amount){
memset(dp, -1, sizeof(dp));
return func(coins.size()-1, amount, coins);


}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
	vector<int>coins = {1,2,5};
	cout<<coinChange(coins,5);
	
}