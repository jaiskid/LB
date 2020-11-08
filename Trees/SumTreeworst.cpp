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
int sum(node*root) {
	if (root == NULL) {
		return 0;
	}
	return sum(root->left) + root->data + sum(root->right);
}
bool Sumtree(node*root) {
	if (root == NULL || root->left == NULL and root->right == NULL) {
		return true;
	}
	int ls = sum(root->left);
	int rs = sum(root->right);
	if ((root->data == ls + rs) and Sumtree(root->left) and Sumtree(root->right))
		return true;
	return false;
}
int main() {
	node*root = buildtree();
	cout << Sumtree(root);
}