#include<bits/stdc++.h>
using namespace std;
int SmallestSubwithSum(int *arr, int n, int x) {
	int curr_sum = 0, min_len = n + 1;
	int start = 0, end = 0;
	while (end < n) {
		//phele add
		while (curr_sum <= x end < n) {
			curr_sum += arr[end++];
		}
		while (curr_sum > x && start < n) {
			//Sirf Subtract
			if (end - start < min_len)
				min_len = end - start;
			curr_sum -= arr[start++];
		}
	}
	return min_len;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int key;
		cin >> key;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << SmallestSubwithSum(arr, n, x) << endl;
	}

}