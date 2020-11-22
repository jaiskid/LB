#include<bits/stdc++.h>
using namespace std;
int setBits(int n) {
	int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}
int main() {
	int  n;
	cin >> n;
	cout << setBits(n);

}