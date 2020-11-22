#include<bits/stdc++.h>
using namespace std;
int difference(int a, int b) {
	int z = a ^ b;
	int count = 0;
	while (z) {
		count += z & 1;
		z >>= 1;
	}
	return count;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << difference(a, b);
}