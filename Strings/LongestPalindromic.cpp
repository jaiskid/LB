#include<bits/stdc++.h>
using namespace std;
void printSubstring(string s, int start, int end) {
	for (int i = start ; i <= end; ++i) {
		cout << s[i];
	}
	cout << endl;
}
int longestPalindromic(string s) {
	int n = s.size();
	bool table[n][n];
	memset(table, 0, sizeof table);
	int start = 0;
	int maxlength = 1;
	int r = 0;
	for (int i = 0; i < n; ++i)
		table[i][i] = true;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true;
			if (r == 0) {
				start = i;
				maxlength = 2;
				r = 1;
			}
		}
	}
	for (int k = 3; k <= n; ++k) {
		for (int i = 0; i < n - k + 1; ++i) {
			int j = i + k - 1;
			if (table[i + 1][j - 1] and s[i] == s[j]) {
				table[i][j] = true;
				if (k > maxlength) {
					start = i;
					maxlength = k;

				}
			}
		}
	}
	printSubstring(s, start, start + maxlength - 1);
	return maxlength;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		longestPalindromic(s);
	}
}