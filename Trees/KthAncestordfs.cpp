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
node* buildTree() {
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	node* root = new node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
node* temp;
node* kthAncestor(node*root, int nod, int k) {
	if (!root)
		return NULL;
	if (root->data == nod || (temp = kthAncestor(root->left, nod, k)) || (temp = kthAncestor(node->right, nod, k))) {
		if (k > 0)
			k--;
		else if (k == 0) {
			cout << root->data << " ";
			return NULL;
		}
		return root;
	}
}
int main() {
	int k;
	cin >> k;
	int node;
	cin >> node;
	node *parent = kthAncestor(root, nod, k);
	if (parent)
		cout << "-1";
}
