#include<bits/stdc++.h>
using namespace std;
// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
int MaximumPathSum(vector<vector<int>>&Matrix, int n) {
	int dp[n][n];
	int ans = INT_MIN;
	int left, right, down;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			left = (i == n - 1 || j == 0) ? 0 : dp[i + 1][j - 1];
			right = (i == n - 1 || j == n - 1) ? 0 : dp[i + 1][j + 1];
			down  = (i == n - 1) ? 0 : dp[i + 1][j];
			dp[i][j] = Matrix[i][j] + max({left, right, down});
		}
	}
	
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[0][i]);
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> Matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Matrix[i][j];
		}
	}
	cout << MaximumPathSum(Matrix, n);
}