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
node* buildree() {
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	node*root = new node(data);
	root->left = buildree();
	root->right = buildree();
	return root;
}
int tosumTree(node*root) {
	if (root == NULL) {
		return 0;
	}
	int old_data = root->data;
	root->data = tosumTree(root->left) + tosumTree(root->right);
	return root->data + old_data;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}
int main() {
	node*root = buildree();
	print(root);
	tosumTree(root);
	print(root);
}