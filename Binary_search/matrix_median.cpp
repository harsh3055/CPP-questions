// calculate the median of the matrix where each row is sorted
#include<iostream>
#include<vector>
using namespace std;
int countNumberLessThanMid(vector<int>&nums, int &mid) {
	int low = 0;
	int high = nums.size() - 1;
	while (low <= high) {
		int md =  (low + high) >> 1;
		if (nums[md] <= mid)
			low = md + 1;
		else
			high = md - 1;
	}
	//cout<<low;
	return low;

}

int solution(vector<vector<int>>& nums) {
	int low = 0;
	int high = 1e9;
	int n = nums.size();
	int m = nums[0].size();
	while (low <= high) {
		int count = 0;
		int mid = (low + high) >> 1;
		for (int i = 0; i < n; i++) {
			count += countNumberLessThanMid(nums[i], mid);
		}
		if (count <= (n * m >> 1)) low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>>nums;
	for (int i = 0 ; i < n; i++) {
		vector<int>temp;
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			temp.push_back(a);
		}
		nums.push_back(temp);

	}
	cout << solution(nums);
}
