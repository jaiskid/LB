#include<bits/stdc++.h>
using namespace std;
int main() {
	string S;
	cin >> S;
	int s = 0;
	int e = S.length() - 1;
	while (s < e) {
		char temp = S[s];
		S[s] = S[e];
		S[e] = temp;
		s++;
		e--;
	}
	cout << S << endl;
}
