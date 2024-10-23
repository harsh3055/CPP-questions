#include<bits/stdc++.h>
using namespace std;

int findelement(vector<int>& arr, int a) {
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (arr[mid] < a) {
			low = mid + 1;
		}
		else if (arr[mid] > a) {
			high = mid - 1;
		}
		else return mid;
	}
	return -1; // Element not found
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findelement(arr, 4);
}
