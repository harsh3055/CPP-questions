#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(const vector<int>& arr) {
	int total_values = 0;
	bool zero_exists = false;
	unordered_map<int, int> counts;
	int num_operations = 0;

	for (auto& val: arr) {
		if (val) total_values++;
		else zero_exists = true;
		counts[val]++;
	}
	if (!zero_exists) {
		num_operations += 2;
		for (auto &val : counts) {
			if (val.second > 1) {
				num_operations--;
				break;
			}
		}
		total_values--;
	}
	num_operations += total_values;
	return num_operations;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (auto& val: arr) cin >> val;
		cout << solve(arr) << endl;
	}
}