#include<bits/stdc++.h>
using namespace std;



int *func(int a) {
	int * b = &a;
	return b;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	char a = 30, b = 40, c = 6;
	char d = a + b * c;
	printf("%d\n", d );
}