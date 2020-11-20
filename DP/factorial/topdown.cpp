#include<bits/stdc++.h>
using namespace std;
// Recursive
int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}
// Topdown
int factorialtopdown(int n, int *dp) {
	if (n == 0) {
		return 1;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	dp[n] = n * factorialtopdown(n - 1, dp);
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	int dp[10005] = {0};
	cout << factorialtopdown(n,dp) << endl;
}