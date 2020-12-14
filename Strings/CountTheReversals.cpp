#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s.size() & 1)
			cout << "-1" << endl;
		else {
			stack<char>st;
			int closing = 0;
			int opening = 0;
			for (int i = 0; i < s.size(); i++) {
				char ch = s[i];
				if (ch == '{') {
					st.push(ch);
					closing++;
				}
				else if (ch == '}' and !st.empty() and st.top() == '{') {
					st.pop();
					closing--;
				}
				else
					opening++;
			}
			if (closing & 1)
				closing = (closing / 2) + 1;
			else
				closing = closing / 2;
			if (opening & 1) {
				opening = (opening / 2) + 1;
			}
			else
				opening = opening / 2;
			cout << opening + closing << endl;
		}
	}
}