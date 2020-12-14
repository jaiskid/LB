#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (start < end) {
		if (s[start++] != s[end--]) {
			return false;
		}
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	(ispalindrome(s) == 1) ? cout << "Yes" : cout << "No";
}