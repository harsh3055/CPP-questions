#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

using namespace std;

int n, x, y;
vector<int> a;
vector<long long> prefix;
unordered_map<long long, int> freq;

int main() {
    cin >> n;
    cin >> x >> y;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]==0) a[i] = x;
        else a[i] = -y;
    }

    prefix.resize(n+1); prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + a[i];
        cout<<prefix[i];
    }

    for (int i = 0; i < n+1; i++) 
        freq[prefix[i]]++;
    long long ans = 0;
    for (pair<long long, int> p : freq) {
        ans += (long long) p.second * (p.second-1) / 2;
    }
    cout << ans << endl;
}