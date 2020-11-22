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
node*construct(node*root, int data) {
	if (root == NULL) {
		root = new node(data);
		return root;
	}
	if (data < root->data)
		root->left = construct(root->left, data);
	else
		root->right = construct(root->right, data);
	return root;
}
void findPreSuc(node*root, node*&pre, node*&suc, int key) {
	if (root == NULL)
		return;
	if (root->data == key) {
		//predecessor
		if (root->left != NULL) {
			node*temp = node->left;
			while (temp->right) {
				temp = temp->right;

			}
			pre = temp;
		}
		//Successor
		if (root->right != NULL) {
			node*temp = node->right;
			while (temp->left) {
				temp = temp->left;

			}
			suc = temp;
		}
	}
	if (root->data > key) {
		//succesor is the root itself and gone to find the preorder
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	}
	else {
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}
void preorder(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	int n;
	cin >> n;
	node*root = NULL;
	while (n--) {
		int data;
		cin >> data;
		root = construct(root, data);
	}
	preorder(root);
}