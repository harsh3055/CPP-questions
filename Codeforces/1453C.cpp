#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using vumii = vector<unordered_map<int, int>>;
using ui = unsigned int;

template<typename T, typename K>
bool contains(T& values, K& value) {
	return values.find(value) != values.end();
}

void set_max(unordered_map<int, int>& values, int key, int val) {
	if (!contains(values, key)) {
		values[key] = val;
		return;
	}
	values[key] = max(values[key], val);
}

vector<vector<int>> convertTo2D(const vector<string>& arr) {
	vector<vector<int>> res;
	for (auto& val: arr) {
		vector<int> temp;
		for (auto& ch: val) {
			temp.emplace_back(ch - '0');
		}
		res.emplace_back(temp);
	}

	return res;
}

pair<vumii, vumii> getRecords(const vector<vector<int>>& arr) {
	pair<vumii, vumii> res = {vumii(arr.size()), vumii(arr.size())};
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			set_max(res.first[i], arr[i][j], max((ui)j, arr.size() - j - 1));
			set_max(res.second[j], arr[i][j], max((ui)i, arr.size() - i - 1));
		}
	}
	return res;
}

int get_area(vumii& values, vector<int>& indices, int i, int j, int val) {
	return max(values[indices[i]][val], values[indices[j]][val]) * (indices[j] - indices[i]);
}

int max_area(vumii& values, int val) {
	int res = -1;
	bool flag = true;
	vector<int> indices;
	for (int i = 0; i < values.size(); i++) {
		if (contains(values[i], val)) indices.emplace_back(i);
	}
	for (int i = 0, j = indices.size() - 1; i < j; i++, j--) {
		vector<int> areas(3, -1);
		areas[0] = get_area(values, indices, i, j, val);
		if (i + 1 < j) areas[1] = get_area(values, indices, i + 1, j, val);
		if (j < j - 1) areas[2] = get_area(values, indices, i, j - 1, val);
		res = max(res, areas[0]);
		for (auto val: areas) {
			res = max(res, val);
		}
	}
	return res;
}

vector<int> solve(const vector<string>& _arr) {
	auto arr = convertTo2D(_arr);
	auto hor_ver_map = getRecords(arr);
	vector<int> res(10);
	for (int i = 0; i < res.size(); i++) {
		auto first = max_area(hor_ver_map.first, i);
		auto second = max_area(hor_ver_map.second, i);
		res[i] = max(0, max(first, second));
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> arr(n);
		for (auto& val: arr) cin >> val;
		auto res = solve(arr);
		for (auto& val: res) cout << val << " ";
		cout << endl;
	}
}