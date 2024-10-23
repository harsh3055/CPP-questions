// finding the nth root of a number using binary search

#include<iostream>
using namespace std;
double multiply(double mid, int n) {
//cout<<mid<<endl;
	double ans = 1.0;
	for (double i = 1; i <= n; i++)
		ans *= mid;
	return ans;

}

double getnthroot(int n, int m) {
	double low = 1;
	double high = m;
	double eps = 1e-6;
	double mid;

	while ((high - low) > eps) {
		mid = (high + low) / 2.0;
// if we multiply the mid n times can we gt the number
		if (multiply(mid, n) < m)
			low = mid;
		else
			high = mid;

	}
	cout << mid;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	int n, m;
	cin >> n >> m;
	getnthroot(n, m);
	return 0;

}