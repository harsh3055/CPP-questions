#include <iostream>
#include<vector>
using namespace std;

void sum(int n, int sumall) {
	if (n < 1) {
		cout << sumall;
		return;
	}
	sum(--n, sumall + n);


}

void reversed(vector<int> nums, int ind) {
	if (ind > nums.size() - 1) return;
	reversed(nums, ind + 1);
	cout << nums[ind];
}
inline void print(vector<int>&ds) {
	for (auto & num : ds)
		cout << num << " ";
}

// void findSubsequence(vector<int>& nums, int &needed, int& sum, vector<int>& ds, int ind, int & count) {
// 	if (ind == nums.size()) {
// 		if (sum == needed) {
// 			print(ds);
// 			count++;
// 			cout << endl;
// 		}

// 		return;
// 	}
// 	ds.push_back(nums[ind]);
// 	needed += nums[ind];
// 	findSubsequence(nums, needed, sum, ds, ind + 1);
// 	ds.pop_back();
// 	needed -= nums[ind];
// 	findSubsequence(nums, needed, sum, ds, ind + 1);

// }
void permutation(vector<int>& vis, vector<int>&nums, vector<int>&ds) {
	if (ds.size() == nums.size())
	{
		for (auto & it : ds)
			cout << it << " ";
		cout << endl;
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (!vis[i]) {
			ds.push_back(nums[i]);
			vis[i] = 1;
			permutation(vis, nums, ds);
			ds.pop_back();
			vis[i] = 0;

		}
	}
}
void permutationswap(vector<int>& nums, vector<int>& ds, int ind) {
	if (ind == nums.size()) {
		for (auto & it : nums)
			cout << it << " ";
		cout << endl;
		return;
	}

	for (int i = ind; i < nums.size(); i++) {
		swap(nums[i], nums[ind]);
		permutationswap(nums, ds, ind + 1);
		swap(nums[ind], nums[i]);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	vector<int>vis(3, 0);
	vector<int>nums{1, 2, 3};
	vector<int>ds;
	//permutation(vis, nums, ds);
	permutationswap(nums, ds, 0);

}


