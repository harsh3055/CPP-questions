// program to reverse a string word by word

#include<iostream>
#include <algorithm> // for std::transform
#include <cctype>    // for ::toupper
using namespace std;

void reverseWord(string &str, int start, int end) {
	while (start <= end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void reverseWordByWord(string &s) {
	int sizeOfString = s.size();
	int startWord = 0;
	for (int i = 0; i < sizeOfString; i++) {
		if (i == ' ' || i == sizeOfString - 1) {
			reverseWord(s, startWord, (i == sizeOfString - 1) ? i : i - 1);
			startWord = i + 1;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	string s;
	getline(cin, s);
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	reverseWordByWord(s);
	cout << s;
}