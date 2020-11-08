#include<bits/stdc++.h>
using namespace std;
void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}
int longestPalindrom(string s) {
	int maxLength = -1;
	int start = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			int flag = 1;
			for (int k = 0; k < (j - i + 1) / 2; k++) {
				if (s[i + k] != s[j - k]) {
					flag = 0;
				}
			}
			if (flag and (j - i + 1) > maxLength) {
				maxLength = j - i + 1;
			}
		}
	}
	printSubStr(str, start, start + maxLength - 1);
	return maxLength;
}
int main() {
	string s;
	cin >> s;
	cout << longestPalindrom(s);
}