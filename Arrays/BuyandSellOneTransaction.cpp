#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int pist = 0;//profit if sale today
	int op = 0; //overall profit
	int lsf = INT_MAX; //least so far
	for (int i = 0; i < n; i++) {
		if (arr[i] < lsf) {
			lsf = arr[i];
		}
		pist = arr[i] - lsf;
		op = max(pist, op);
	}
	cout << op << endl;
}