#include<bits/stdc++.h>
using namespace std;
int isPlaindrome(string S)
{
	// Your code goes here
	int s = 0;
	int e = S.size() - 1;
	while (s < e) {
		if (S[s] != S[e]) {

			return false;

		}
		s++;
		e--;
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	cout << isPlaindrome(s);
}