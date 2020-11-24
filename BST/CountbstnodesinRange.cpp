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
node*construct(node*root, int data) {
	if (root == NULL) {
		root = new node(data);
		return root;
	}
	if (data < root->data) {
		root->left = construct(root->left, data);
	}
	else {
		root->right = construct(root->right, data);
	}
	return root;
}
int count(node*root, int l, int h) {
	if (root == NULL)
		return 0;
	if (root->data == l and root->data == h)
		return 1;
	if (root->data >= l and root->data <= h) {
		return 1 + count(root->left, l, h) + count(root->right, l, h);
	}
	if (root->data < l) {
		return count(root->right, l, h);
	}
	else
		return count(root->left, l, h);
}
int main() {
	node*root = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		root = construct(root, data);
	}
	int l, h;
	cin >> l >> h;
	cout << count(root, l, h);
}