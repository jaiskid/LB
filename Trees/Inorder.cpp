#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node *left, *right;
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
	node*root = new node(data);
	root->left = buildtree();
	root->right =  buildtree();
	return root;
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
	node*root = buildtree();
	print(root);
}