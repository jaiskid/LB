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
	if (root->data > data) {
		root->left = construct(root->left, data);
	}
	else {
		root->right = construct(root->right, data);
	}
	return root;
}
int Lca(node*root, int n1, int n2) {
	if (root->data < n1 and root->data < n2) {
		return Lca(root->right, n1, n2);
	}
	else if (root->data > n1  and root -> data > n2) {
		return Lca(root->left, n1, n2);
	}
	return root->data;
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
		int data;
		cin >> data;
		root = construct(root, data);
	}
	preorder(root);
	int n1, n2;
	cin >> n1 >> n2;
	cout << Lca(root, n1, n2);
}