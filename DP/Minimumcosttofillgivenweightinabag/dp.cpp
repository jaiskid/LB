#include<bits/stdc++.h>
using namespace std;
int minimumCost(int *cost, int n, int w) {
	vector<int> val, wt;
	int size = 0;
	for (int i = 0; i < n; i++) {
		if (cost[i] != -1) {
			val.push_back(cost[i]);
			wt.push_back(i + 1);
			size++;
		}
	}
	n = size;
	int t[n + 1][w + 1];
	for (int i = 0; i < w + 1; i++) {
		t[0][i] = INT_MAX;
	}
	for (int i = 0; i < n + 1; i++) {
		t[i][0] = 0;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			if (wt[i - 1] <= j)
				t[i][j] = min(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
			else if (wt[i - 1] > j)
				t[i][j] = t[i - 1][j];
		}
	}
	return (t[n][w] == INT_MAX) ? -1 : t[n][w];
}
int main() {
	int n;
	cin >> n;
	int cost[n];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	int w;
	cin >> w;
	cout << minimumCost(cost, n, w);
}