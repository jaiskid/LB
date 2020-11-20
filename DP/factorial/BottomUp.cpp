#include<bits/stdc++.h>
using namespace std;
int bottomUp(int n) {
	int dp[n];
	// memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = i * dp[i - 1];
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout << bottomUp(n);
	cout << factorialLoop(n);
}