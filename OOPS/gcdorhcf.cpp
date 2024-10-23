#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//time complexity is ologk space is o(n);

// gcd(a, b) = gcd(a-b, b) where a>b
// gcd(a, b) = gcd(a%b, b) where a>b

int gcd(int a , int b) {
    while (a > 0 and b > 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    if (a == 0) return b;
    if (b == 0) return a;
}

int gcdf( int a , int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 and b % i == 0)
            return i;
    }
}

int gcdi(int a , int b) {
    int ans = 1;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 and b % i == 0)
            ans = i;
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    // int n;
    // cin >> n;
    // vector<int>nums(n);
    // priority_queue<int, vector<int>, greater<int>>pq;
    // for (int i = 0; i < n; i++) {
    //     cin >> nums[i];
    // }
    // for (auto& it : nums) {
    //     pq.push(it);
    //     if (pq.size() > 2) {
    //         pq.pop();
    //     }
    // }
    // cout << pq.top();
    int a = 52, b = 10;
    cout << gcd(10, 15) << endl;
    cout << gcdf(2, 10) << endl;
    cout << gcdi(2, 10) << endl;
}
