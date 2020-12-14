#include<bits/stdc++.h>
using namespace std;
string s;
static int dp[10005][10005];
int countPs(string s, int start, int end) {
	if (start > end)
		return 0;
	if (dp[start][end] != -1) {
		return dp[start][end];
	}
	if (start == end) {
		return dp[start][end] = 1;
	}
	else if (s[start] == s[end]) {
		return dp[start][end] = 1 + countPs(s, start + 1, end) + countPs(s, start, end - 1);
	}
	else {
		return dp[start][end] = countPs(s, start + 1, end) + countPs(s, start, end - 1) - countPs(s, start + 1, end - 1);
	}
}
int main() {
	cin >> s;
	memset(dp, -1, sizeof dp);
	cout << countPs(s, 0, s.size() - 1);
}