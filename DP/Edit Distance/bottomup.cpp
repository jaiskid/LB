#include<bits/stdc++.h>
using namespace std;
int editDistance(string x, string y) {
	int m = x.size();
	int n = y.size();
	int dp[m+1][n+1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0) {
				dp[i][j] = j;
			}
			else if (j == 0) {
				dp[i][j] = i;
			}
			else if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
				dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}
	return dp[m][n];
}
int main() {
	string x, y;
	cin >> x >> y;
	cout << editDistance(x, y);
}