#include<bits/stdc++.h>
using namespace std;
char flip(char ch) {
	return (ch == '0') ? '1' : '0';
}

int getFlipwithStarting(string s, int expected) {
	int flipCount = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != expected)
			flipCount++;
		expected = flip(expected);
	}
	return flipCount;
}
int main() {
	string s;
	cin >> s;
	cout << min(getFlipwithStarting(s, '0'), getFlipwithStarting(s, '1'));
}