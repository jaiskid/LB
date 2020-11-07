#include<bits/stdc++.h>
//Root to node path iski complexity toh o(n) he but ye tin baar chalta h
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
bool findPath(node*root, vector<int>&path, int k) {
	if (root == NULL) {
		return false;
	}
	path.push_back(root->data);
	if (root->data == k) {
		return true;
	}
	if (root->left and findPath(root->left, path, k) || root->right and findPath(root->right, path, k))
		return true;
	path.pop_back();
	return false;
}
int findLCA(node*root, int n1, int n2) {
	vector<int>path1, path2;
	if (!findPath(root, path1, n1) || !findPath(root, path2, n2)) {
		return -1;
	}
	int i;
	for (i = 0; i < path1.size(), i < path2.size(); i++) {
		if (path1[i] != path2[i])
			break;
	}
	return path1[i - 1];
}
int main() {
	node*root = buildtree();
	int n1;
	cin >> n1;
	int n2;
	cin >> n2;
	cout << findLCA(root, n1, n2);
}