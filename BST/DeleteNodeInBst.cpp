//Before we start
// handle these cases
// Node to be deleted is leaf
//Node to be deleted has only one child
//Node to deleted has two children
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left;
	node*right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node* construct(node*root, int data) {
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
void preorder(node*root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int max(node*root) {
	if (root ->right != NULL) {
		return max(root->right);
	}
	else
		return root->data;
}
node* deleteNode(node*root, int data) {
	if (root == NULL)
		return NULL;
	if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else if (data < root->data) {
		root->left = deleteNode(root->left, data);
	}
	else {
		if (root->left != NULL and root->right != NULL) {
			int lmax = max(root->left);
			root->data = lmax;
			root->left = deleteNode(root->left, lmax);
		}
		else if (root->left != NULL) {
			return root->left;
		}
		else if (root->right != NULL) {
			return root->right;
		}
		else {
			return NULL;
		}
	}
	return root;
}
int main() {
	node*root = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		root =	construct(root, data);
	}
	preorder(root);
	int key;
	cin >> key;
	root = deleteNode(root, key);
	preorder(root);
}