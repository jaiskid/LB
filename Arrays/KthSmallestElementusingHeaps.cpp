#include<bits/stdc++.h>
using namespace std;
int Kthsmallest(int *arr, int k, int n) {
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		//insertion
		pq.push(arr[i]);
		if (pq.size() > k) {
			pq.pop();
		}
	}
	return pq.top();
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int k;
		cin >> k;
		cout << Kthsmallest(arr, k, n);
	}
}
1
6
7 10 4 3 20 15
3
3 4 7 10 15 20