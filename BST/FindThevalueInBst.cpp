#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
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
node* search(node*root, int key) {
	if (root == NULL || root->data == key) {
		return root;
	}
	if (root->data < key) {
		return search(root->right, key);
	}
	return search(root->left, key);
}
void preorder(node*root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	node* root = NULL;
	int n;
	cin >> n;
	while (n--) {
		int d;
		cin >> d;
		root = construct(root, d);
	}
	preorder(root);
	int key;
	cin >> key;
	root = search(root, key);
	if (root == NULL)
		cout << -1;
	else
		cout << root->data;
}