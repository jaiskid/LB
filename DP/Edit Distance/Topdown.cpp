#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int editDistance(string x, string y, int m, int n) {
	if (m == 0) {
		return n;
	}
	if (n == 0) {
		return m;
	}
	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	if (x[m - 1] == y[n - 1])
		return dp[m][n] = editDistance(x, y, m - 1, n - 1);
	return dp[m][n] = 1 + min(min(editDistance(x, y, m, n - 1), editDistance(x, y, m - 1, n)), editDistance(x, y, m - 1, n - 1));
}
int main() {
	memset(dp, -1, sizeof dp);
	string x, y;
	cin >> x >> y;
	int  m = x.size();
	int n = y.size();
	cout << editDistance(x, y, m, n);
}