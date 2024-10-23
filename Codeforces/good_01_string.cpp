#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

pair<int, int> solve(string str) {
	vector<bool> even_odd;
	list<pair<int, char>> segments;
	int start = 0;
	int num_operations = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) {
			even_odd.emplace_back((i - start) % 2);
			segments.emplace_back(i - start, str[i - 1]);
			start = i;
		}
	}
	even_odd.emplace_back((str.size() - start) % 2);
	segments.emplace_back(str.size() - start, str.back());
	auto segment = next(segments.begin());
	for (int i = 1; i < even_odd.size(); i++) {
		if (!even_odd[i - 1] && !even_odd[i]) goto end;
		if (!even_odd[i - 1] && even_odd[i]) {
			if (i == even_odd.size() - 1) cout << "Something is not right";
			goto end;
		}
		if (even_odd[i - 1] && even_odd[i]) {
			num_operations++;
			even_odd[i - 1] = 0;
			even_odd[i] = 0;
			auto prev_segment = prev(segment);
			if ((i != 1 && prev_segment->first <= segment->first) || (prev_segment->first < segment->first)) {
				prev_segment->first--;
				segment->first++;
			} else {
				prev_segment->first++;
				segment->first--;
			}
		}
		else {
			num_operations++;
			even_odd[i - 1] = 0;
			even_odd[i] = 1;
			auto prev_segment = prev(segment);
			if ((i != 1 && prev_segment->first <= segment->first) || (prev_segment->first < segment->first)) {
				prev_segment->first--;
				segment->first++;
			} else {
				prev_segment->first++;
				segment->first--;
			}
		}
end:;
		segment = next(segment);
		while (!prev(segment)->first || prev(segment)->second == segment->second) {
			if (prev(segment)->first > 0) segment->first += prev(segment)->first;
			segments.erase(prev(segment));
		}
	}
	int num_subsegments = 0;
	segment = segments.begin();
	while (segment != segments.end()) {
		auto _next = next(segment);
		// cout << "{" << segment->first << " " << segment->second << "} ";
		if (segment->first && (segment == segments.begin() || (prev(segment)->second != segment->second))) {
			num_subsegments++;
		} else {
			segments.erase(segment);
		}
		segment = _next;
	}
	// cout << endl;
	return {num_operations, num_subsegments};
}

template<typename M, typename N>
string to_string(const pair<M, N>& values) {
	return to_string(values.first) + " " + to_string(values.second);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin.ignore();
		string str;
		getline(cin, str);
		auto soln = solve(str);
		reverse(str.begin(), str.end());
		auto rev_soln = solve(str);
		if (soln.second > rev_soln.second) soln = rev_soln;
		cout << to_string(soln) << endl;
	}
}