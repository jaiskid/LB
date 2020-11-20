#include<bits/stdc++.h>
using namespace std;
int Knapsack(int *wt, int *val, int W, int n) {
	//Base case
	if (n == 0 || W == 0) {
		return 0;
	}
	//Recursive Case
	if (wt[n - 1] <= W) {
		return max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1), Knapsack(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W) {
		return Knapsack(wt, val, W, n - 1);
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
	cout << Knapsack(wt, val, W, n);
}