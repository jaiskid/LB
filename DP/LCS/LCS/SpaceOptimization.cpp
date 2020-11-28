#include<bits/stdc++.h>
using namespace std;
int lcs(string x, string y, int m, int n) {
	int dp[2][n + 1];
	bool bi;
	for (int i = 0; i < m + 1; i++) {
		bi = i & 1;
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0) {
				dp[bi][j] = 0;
			}
			else if (x[i - 1] == y[j - 1])
				dp[bi][j] = dp[1 - bi][j - 1] + 1;
			else
				dp[bi][j] = max(dp[1 - bi][j - 1], dp[bi][j - 1]);
		}
	}
	return dp[bi][n];
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << lcs(x, y, m, n);
}