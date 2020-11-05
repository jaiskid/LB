#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node *left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node* buildTree(int *in, int *pre, int start, int end, unordered_map<int, int>&mp) {
	static int preindex = 0;
	if (start > end) {
		return NULL;
	}
	int curr = pre[preindex++];
	node* root = new node(curr);
	if (start == end) {
		return root;
	}
	int index = mp[curr];
	root->left = buildTree(in, pre, start, index - 1, mp);
	root->right = buildTree(in, pre, index + 1, end, mp);
	return root;
}
node* buildWrap(int *in, int *pre, int n) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[in[i]] = i;
	}
	return buildTree(in, pre, 0, n - 1, mp);
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	print(root->right);
	cout << root->data << " ";
}
int main() {
	int n;
	cin >> n;
	int in[n];
	int pre[n];
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	node*root = buildWrap(in, pre, n);
	print(root);
}