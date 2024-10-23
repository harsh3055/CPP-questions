// C++ code to illustrate minimum characters to be added at
// front to make string palindrome using O(1) space
#include <bits/stdc++.h>
using namespace std;
int minChar(string str)
{
	// Write your code here
	int n = str.length();
	int left = 0;
	int right = n - 1;
	int added = 0;
	while (left < right) {
		// if left and right characters are same increase
		// left and decrease right pointer
		if (str[left] == str[right]) {
			//cout<<str[left]<<str[right]<<" e"<<endl;
			left++;
			right--;
		}
		// else think of adding some characters at front and
		// start comparing the elements again
		else {
			left = 0;
			added = n - right;
			// cout<<n<<right<<"nr"<<endl;
			// cout<<" add "<<added<<endl;
			while (str[left] == str[right]) {
				//cout<<str[left]<<str[right]<<" ue"<<endl;
				added--;
				left++;
				//cout<<added<<endl;
			}
			right--;
		}
	}
	return added;
}
// Driver program to test above functions
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	string str = "abaacde";
	cout << minChar(str);
	return 0;
}
