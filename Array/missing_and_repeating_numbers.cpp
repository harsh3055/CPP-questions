#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums, int n) {
    int repeat = -1 ,  missing = -1;

    for (int i = 0; i < n; i++)
    {
        int v = abs(nums[i]) - 1;
        if (nums[v] < 0)
        {
            repeat = abs(nums[i]);
        }
        else
            nums[v] = -1 * nums[v];
    }

    // find out the missing element , there will be one positive value

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            missing = i + 1;
        }
    }


    cout << repeat << " " << missing;

}




int main() {

#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

    int n;
    cin >> n;
    vector<int>nums;

    for (int i = 0 ; i < n; i++)s
    {
        int a; cin >> a;
        nums.push_back(a);
    }



    solve(nums, n);
}