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
node* buildtree() {
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	node* root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
node* findLca(node*root, int n1, int n2) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == n1 || root->data == n2) {
		return root;
	}
	node* left_root = findLca(root->left, n1, n2);
	node* right_root = findLca(root->right, n1, n2);
	if (left_root and right_root) {
		return root;
	}
	return (left_root != NULL) ? left_root : right_root;
}
int count(node*root, int val, int level) {
	if (root == NULL) {
		return -1;
	}
	if (root->data == val) {
		return level;
	}
	int d = count(root->left, val, level + 1);
	if (d != -1)
		return d;
	d = count(root->right, val, level + 1);
	return d;
}
int findDist(node*root, int a, int b) {
	if (root == NULL) {
		return 0;
	}
	node* final = findLca(root, a, b);
	int d1 = count(final, a, 0);
	int d2 = count(final, b, 0);
	return d1 + d2;
}
int main() {
	node* root = buildtree();
	int a, b;
	cin >> a >> b;
	cout << findDist(root, a, b);
}