#include<bits/stdc++.h>
using namespace std;
bool checker(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' or s[i] == '{' or s[i] == '[')
			st.push(s[i]);

		else if (s[i] == ')') {
			if (!st.empty() and st.top() == '(') {
				st.pop();
				continue;
			}
			else
				return false;
		}
		else if (s[i] == '}') {
			if (!st.empty() and st.top() == '{') {
				st.pop();
				continue;
			}
			else
				return false;
		}
		else if (s[i] == ']') {
			if (!st.empty() and st.top() == '[') {
				st.pop();
				continue;
			}
			else
				return false;
		}

	}
	if (st.empty())
		return true;
	else
		return false;
}
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << checker(s);
	return 0;
}