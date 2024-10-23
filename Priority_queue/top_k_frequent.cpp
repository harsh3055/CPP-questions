// we have to find the frequent numbers

#include<iostream>
// we have to find the number which are occuring more than once
// use minheap and hashing to do this queation
// minimum elements come at the top in maxheap

#include<vector>
#include <unordered_map>
#include<queue>
using namespace std;
typedef pair<int, int>  pii;

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n; cin >> n;
	int k ; cin >> k;
	vector<int>nums(n);
	for (auto &num : nums)
		cin >> num;

	unordered_map<int, int>mp;
	priority_queue<pii, vector<pii> , greater<pii>>minh;

	for (auto &val : nums) {
		mp[val]++;
	}
	for (auto  i = mp.begin(); i != mp.end(); i++) {
		minh.push({i->second, i->first});
		if (minh.size() > k)
			minh.pop();
	}
	while (minh.size() > 0) {
		cout << minh.top().second << endl;
		minh.pop();
	}

}