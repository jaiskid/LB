#include<bits/stdc++.h>
using namespace std;
int goldMines(vector<vector<int>>gold) {
	int goldtable[gold.size()][gold.size()];
	for (int col = gold.size() - 1; col >= 0; col--) {
		for (int row = 0; row < gold.size(); row++) {
			//(->)
			int right = (col == gold.size() - 1) ? 0 : goldtable[row][col + 1];
			//(/)
			int right_up = (row == 0 || col == gold.size() - 1) ? 0 : goldtable[row - 1][col + 1];
			//(\)
			int right_down = (row == gold.size() - 1 || col == gold.size() - 1) ? 0 : goldtable[row + 1][col + 1];
			goldtable[row][col] = gold[row][col] + max(right, max(right_up, right_down));
		}
	}
	int res = goldtable[0][0];
	for (int i = 1; i < gold.size(); i++) {
		res =  max(res, goldtable[i][0]);
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>>gold(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < gold[0].size(); j++) {
			cin >> gold[i][j];
		}
	}
	cout << goldMines(gold);
}