#include<bits/stdc++.h>
using namespace std;
char* reverse(char* str) {
	stack<char> st;
	int i = 0;
	while (str[i] != '\0') {
		st.push(str[i++]);
	}
	i = 0;
	while (!st.empty()) {
		str[i] = st.top();
		i++;
		st.pop();
	}
	return str;
}
int main() {
	char str[10005];
	cin >> str;
	cout << reverse(str);
	return 0;
}