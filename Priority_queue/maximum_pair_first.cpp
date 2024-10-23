// input is 2d vector and we have to print a 2d vector where
// input
/*
5
2 5
2 8
1 3
1 1
3 3

output is
1 3
1 1
2 8
2 5
3 3
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include <algorithm>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n;
	cin >> n;
	vector<vector<int>>v;
	vector<int>val;
	unordered_map<int, priority_queue<int>>mp;
	int a;
	for (int i = 0 ; i < n; i++ )
	{
		vector<int>temp;
		for (int j = 0; j < 2; j++) {
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}


	for (int i = 0 ; i < n ; i++)
		val.push_back(v[i][0]);

	sort(val.begin(), val.end());


	for (int i = 0 ; i < n; i++)
		mp[v[i][0]].push(v[i][1]);


	for (int i = 0; i < n; i++) {
		while (mp[val[i]].empty() == false) {
			cout << val[i] << " " << mp[val[i]].top() << endl;
			mp[val[i]].pop();
		}
	}
}