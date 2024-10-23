// find the element which is coming one time in sorted array
// this is the basic approach
// the xor of the same element is 0 so at the end you will be left with the elemnt with the element having the frequency of 1
// time complexity o(n)
// space complexity o(1)
#include<iostream>
#include<vector>
// this will take log n time
// we are seaching for the partition where

int merge(int arr[], int n) {
	// here we are applying two pointers approach
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		// xor of odd number with 1 will give you number less than it
		// xor of even number with 1 will give you number greater than it
		if (arr[mid] == arr[mid ^ 1])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return arr[mid];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n; cin >> n;
	int arr[n];
	for (int i = 0 ; i < n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans ^ arr[i];
	}
	cout << merge(arr, n);
}
