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
	node* left_lca = findLca(root->left, n1, n2);
	node* right_lca = findLca(root->right, n1, n2);
	if (left_lca and right_lca) {
		return root;
	}
	return (left_lca != NULL) ? left_lca : right_lca;
}
int main() {
	node* root = buildtree();
	int n1, n2;
	cin >> n1 >> n2;
	cout << findLca(root, n1, n2)->data;
}