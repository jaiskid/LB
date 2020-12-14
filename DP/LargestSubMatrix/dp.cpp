#include<bits/stdc++.h>
using namespace std;
int LargestSubMatrix(vector<vector<int>>&arr, int m, int n) {
	int dp[m + 1][n + 1];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				dp[i][j] = arr[i][0];
			}
			if (j == 0) {
				dp[i][j] = arr[0][j];
			}
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == 1) {
				dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	int mx = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mx < dp[i][j]) {
				mx = dp[i][j];
			}
		}
	}
	return mx;
}
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>>arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << LargestSubMatrix(arr, m, n);
}