#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr[1005][1005];
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	int key;
	cin >> key;
	int i = 0;
	int j = n - 1;
	while (i<n and j >= 0) {
		if (key == arr[i][j]) {
			cout << i << " " << j << endl;
			return 0;
		}
		else if (key < arr[i][j]) {
			j--;
		}
		else {
			i++;
		}
	}
	cout << "Not found" << endl;
}