#include<bits/stdc++.h>
using namespace std;
void Subsequence(string s, string ans) {
	if (s.size() == 0) {
		cout << ans << " ";
		return;
	}
	char ch = s[0];
	string ros = s.substr(1);
	Subsequence(ros, ans);
	Subsequence(ros, ans + ch);
}
int main() {
	string s;
	cin >> s;
	Subsequence(s, "");
}