#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int pist = 0;
	int op = 0;
	int lsf = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (arr[i] < lsf) {
			lsf = arr[i];
		}
		pist = arr[i] - lsf;
		op = max(pist, op);
	}
	cout << op << endl;
}