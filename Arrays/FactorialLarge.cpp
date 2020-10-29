#include<bits/stdc++.h>
using namespace std;
int multiply(int number , int *resultArray, int resultarraysize) {
	int carry = 0, mulRes;
	for (int i = 0; i < resultarraysize; i++) {
		mulRes = resultArray[i] * number + carry;
		resultArray[i] = mulRes % 10;
		carry = mulRes / 10;
	}
	while (carry) {
		resultArray[resultarraysize++] = carry % 10;
		carry = carry / 10;
	}
	return resultarraysize;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int resultArray[1005];
		int resultarraysize = 1;
		resultArray[0] = 1;
		while (n) {
			resultarraysize = multiply(n--, resultArray, resultarraysize);

		}
		for (int i = resultarraysize - 1; i >= 0; i--) {
			cout << resultArray[i];
		}
		cout << endl;
	}

}