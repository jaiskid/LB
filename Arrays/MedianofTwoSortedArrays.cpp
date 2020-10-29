#include<bits/stdc++.h>
using namespace std;
int getMedian(int *a, int *b, int n) {
	int i = 0;
	int j = 0;
	int count;
	int m1 = -1, m2 = -1;
	for (count = 0 ; count <= n; count++) {
		/* Below is to handle case where
		  all elements of a[] are
		  smaller than smallest(or first)
		  element of b[]*/
		if (i == n) {
			m1 = m2;
			m2 = b[0];
			break;
		}
		/* Below is to handle case where
		   all elements of b[] are
		   smaller than smallest(or first)
		   element of a[]*/
		if (j == n) {
			m1 = m2;
			m2 = a[0];
			break;
		}
		if (a[i] <= b[j]) {
			m1 = m2;
			m2 = a[i];
			i++;
		}
		else {
			m1 = m2;
			m2 = b[j];
			j++;
		}
	}
	return (m1 + m2) / 2;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	cout << getMedian(a, b, n);
}