#include<bits/stdc++.h>
using namespace std;
int x = 0;
int y = 0;
void getTwoNon(int *arr, int n) {
	int Xor = arr[0];
	int set_bit_no;
	for (int i = 1; i < n; i++) {
		Xor ^= arr[i];
	}
	set_bit_no = Xor & ~(Xor - 1);
	for (int i = 0; i < n; i++) {
		if (set_bit_no & arr[i])
			x ^= arr[i];
		else
			y ^= arr[i];
	}
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	getTwoNon(arr, n);
	cout << x << " " << y;
}