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
int TreeSum(node*root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL and root->right == NULL) {
		return root->data;
	}
	else {
		if (root->data == TreeSum(root->left) + TreeSum(root->right)) {
			return 2 * root->data;
		}
	}
	return 0;
}
bool isSumtree(node*root) {
	if (root->data  == TreeSum(root) / 2) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	node* root = buildtree();
	cout << isSumtree(root);
}