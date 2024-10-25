// C++ program for the implementation of Selection sort
#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {

      int beginning_index = i;
      int smallest;
      for(int j = i+1; j< n; j++){
          if(v[j]<v[j-1]){
             smallest = j;
          }
      }
      swap(v[beginning_index], v[smallest]);
    }
}

int main() {
    vector<int> v = {5, 10, 4, 2, 8};

    selection_sort(v);
    for (auto i : v)
        cout << i << " ";
    return 0;
}
