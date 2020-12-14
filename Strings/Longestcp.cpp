#include<bits/stdc++.h>
using namespace std;
// Time O(n*k) , k is the length of the common prefix
// Space O(1)

string longestCommonPrefix(vector<string>&strs) {
	if (!strs.size())
		return "";
	for (int i = 0; strs[0].size(); i++) {
		for (const auto &str : strs) {
			if (i >= str.length() || str[i] != strs[0][i]) {
				return strs[0].substr(0, i);
			}
		}
	}
	return strs[0];
}
int main() {
	int n; 
	cin >> n;
	vector<string> s;
	s.resize(n);
	for (int i = 0; i < s.size(); i++) {
		cin >> s[i];
	}
	cout << longestCommonPrefix(s);
}