#include<bits/stdc++.h>
using namespace std;
int BinaryMedian(int m[][1005], int r, int c) {
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < r; i++) {
		if (m[i][0] < min) {
			min = m[i][0];
		}
		if (m[i][c - 1] > max) {
			max = m[i][c - 1];
		}
	}
	int desired = (r * c + 1) / 2;
	while (min < max) {
		int mid = min + (max - min) / 2;
		int place = 0;
		//Find count of element smaller than mid
		for (int i = 0; i < r; i++) {
			place += upper_bound(m[i], m[i] + c, mid) - m[i];

		}
		if (place < desired)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}
int main() {
	int r, c;
	cin >> r >> c;
	int m[1005][1005];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
		}
	}
	cout << BinaryMedian(m, r, c) << endl;
	return 0;
}