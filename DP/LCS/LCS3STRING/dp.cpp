#include<bits/stdc++.h>
using namespace std;
int lcs3String(string x, string y, string z, int m , int n, int o) {
	int dp[m + 1][n + 1][o + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 1; k < o + 1; k++) {
				if (x[i - 1] == y[j - 1] and x[i - 1] == z[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
				}
			}
		}
	}
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			for (int k = 0; k < o + 1; k++) {
				cout << dp[i][j][k] << " ";
			}
		}
		cout << endl;
	}
	return dp[m][n][o];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int  m, n, o;
		cin >> m >> n >> o;
		string x, y, z;
		cin >> x >> y >> z;
		cout << lcs3String(x, y, z, m, n, o) << endl;
	}

}