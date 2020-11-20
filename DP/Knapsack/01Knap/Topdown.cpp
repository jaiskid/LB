#include<bits/stdc++.h>
using namespace std;
static int dp[10005][10005];

int TopDown(int *wt, int *val, int W, int n) {
	if (n == 0 || W == 0) {
		return 0;
	}
	if (dp[W][n] != -1) {
		return dp[W][n];
	}
	if (wt[n - 1] <= W) {
		return dp[W][n] = max(val[n - 1] + TopDown(wt, val, W - wt[n - 1], n - 1), TopDown(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W) {
		return dp[W][n] = TopDown(wt, val, W, n - 1);
	}
}
int main() {
	int n;
	cin >> n;
	int wt[n];
	int val[n];
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}
	int W;
	cin >> W;
	memset(dp, -1, sizeof dp);
	cout << TopDown(wt, val, W, n);
}