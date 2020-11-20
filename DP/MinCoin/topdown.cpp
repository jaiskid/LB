#include<bits/stdc++.h>
using namespace std;
int Mincoins(int amount, int *coins, int n) {
	if (n == 0) {
		return 0;
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (amount - coins[i] >= 0) {
			int smallsolution = Mincoins(amount - coins[i], coins, n);
			cout << "Hello" << " ";
			ans = min(ans , smallsolution + 1);
		}
	}
	return ans;
}
int main() {
	int amount;
	cin >> amount;
	int n;
	cin >> n;
	int coins[10005];
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	cout << Mincoins(amount, coins, n);
}
