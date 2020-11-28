#include<bits/stdc++.h>
using namespace std;
int binomial(int n, int k) {
	if (k > n) {
		return 0;
	}
	if (k == 0 || k == n) {
		return 1;
	}
	return binomial(n - 1, k - 1) + binomial(n - 1, k);
}
int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	cout << binomial(n, k);
	return 0;
}