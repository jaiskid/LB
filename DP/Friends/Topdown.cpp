#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int friendPairing(int n) {
	if (n <= 2)
		return n;
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = friendPairing(n - 1) + (n - 1) * friendPairing(n - 2);
}
int main(int argc, char const *argv[])
{
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << friendPairing(n);
	return 0;
}