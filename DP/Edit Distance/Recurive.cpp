#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z) {
	return min(min(x, y), z);
}
int editDistance(string x, string y, int m, int n) {
	if (m == 0) {
		return n;
	}
	if (n == 0) {
		return m;
	}
	if (x[m - 1] == y[n - 1]) {
		return editDistance(x, y, m - 1, n - 1);
	}
	return 1 + min(editDistance(x, y, m, n - 1), editDistance(x, y, m - 1, n), editDistance(x, y, m - 1, n - 1));
}
int main() {
	string x;
	string y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << editDistance(x, y, m, n);
}