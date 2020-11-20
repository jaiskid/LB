#include<bits/stdc++.h>
using namespace std;
int topdown(int n, int *dp) {
	if (n == 0 || n == 1) {
		return n;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	dp[n] = topdown(n - 1, dp) + topdown(n - 2, dp);
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	int dp[10005] = {0};
	cout << topdown(n,dp);
}