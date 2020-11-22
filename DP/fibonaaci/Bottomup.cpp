#include<bits/stdc++.h>
using namespace std;
int bottomup(int n) {
	int dp[10005];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout << bottomup(n);
}