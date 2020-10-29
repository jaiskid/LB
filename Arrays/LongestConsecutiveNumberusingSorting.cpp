#include<bits/stdc++.h>
using namespace std;
//failed to handle the duplicates
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
		sort(arr, arr + n);
		int count = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 and arr[i] == arr[i - 1] + 1)
				count++;
			else
				count = 1;
			ans = max(ans, count);
		}
		cout << ans << endl;
	}
}