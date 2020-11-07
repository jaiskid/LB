#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
int findIndex(string str, int start, int end) {
	if (start > end) {
		return -1;
	}
	stack<char>s;
	for (int i = start; i <= end; i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();
				if (s.empty())
					return i;
			}
		}
	}
	return -1;
}
node* buildtreeFromString(string s, int start, int end) {
	if (start > end) {
		return NULL;
	}
	node* root = new node(s[start] - '0');
	int index = -1;
	if (start + 1 <= end and s[start + 1] == '(') {
		index = findIndex(s, start + 1, end);
	}
	if (index != -1) {
		root->left = buildtreeFromString(s, start + 2, index - 1);
		root->right = buildtreeFromString(s, index + 2, end - 1);
	}
	return root;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
int main() {
	string s;
	cin >> s;
	node*root = buildtreeFromString(s, 0, s.size() - 1);
	print(root);
}