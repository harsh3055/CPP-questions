#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int main() {


#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif



    int n;
    cin >> n;

    vector<int> boxes(n);
// taking input
    for (int i = 0; i < n; i++)
        cin >> boxes[i];

// maintaining count of each element
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
        mpp[boxes[i]]++;

    // flg to check if result is -1
    bool flg = false;
    int minRounds = 0;      // to keep count of min rounds
    for (pair<int, int> p : mpp) {
        int cnt = p.second;
        if (cnt < 2) {      // if cnt is less than 2 we cannot take this box in any round so set flg to true for -1
            flg = true;
            break;
        }
        else if (cnt % 3 == 0) {
            minRounds += cnt / 3;          // else min number of rounds are cnt/3 + 1
        }
        else
            minRounds += (cnt / 3 + 1) ;

    }
    if (flg)
        cout << -1 << endl;
    else
        cout << minRounds << endl;
}