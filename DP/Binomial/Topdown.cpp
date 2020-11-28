#include<bits/stdc++.h>
using namespace std;
int t[1005][1005];
int binomial(int n, int k) {
	if (k > n) {
		return 0;
	}
	if (k == 0 || k == n) {
		return 1;
	}
	if (t[k][n] != -1) {
		return t[k][n];
	}
	return t[k][n] = binomial(n - 1, k - 1) + binomial(n - 1, k);
}
int main() {
	memset(t, -1, sizeof t);
	int n;
	cin >> n;
	int k;
	cin >> k;
	cout << binomial(n, k);
}