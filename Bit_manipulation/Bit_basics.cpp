// Simple bit manipulation functions in c++
#include <bits/stdc++.h>
using namespace std;

void get_bit(int num, int position) {
    int filter = 1 << position;
    int bit = num & filter;
    cout << bit;

}
void set_bit(int num, int position) {
    int filter = 1 << position;
    num |= filter;
    cout << num;
}
void clear_bit(int num, int position) {
    int filter = (1 << position);
    num &= (~filter);
    cout << num;
}
void update_bit(int num, int position, int action) {
    if (action) {
        set_bit(num, position);
    } else {
        clear_bit(num, position);
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    int number = 5; //101
    int position = 2;

    // get_bit(number, position);
    // set_bit(number, position);
    // update_bit(number, position, /*1 or 0*/ 1);
    // clear_bit(number, position);

}
