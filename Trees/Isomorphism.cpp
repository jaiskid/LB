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
	node *root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
bool isomorphic(node*root1, node*root2) {
	if (root1 == NULL and root2 == NULL) {
		return true;
	}
	if (root1 == NULL || root2 == NULL) {
		return false;
	}
	if (root1->data != root2->data) {
		return false;
	}
	return (isomorphic(root1->left, root2->left) and isomorphic(root1->right, root2->right)) || (isomorphic(root1->left, root2->right) and isomorphic(root1->right, root2->left));
}
int main() {
	node*root1 = buildtree();
	node*root2 = buildtree();
	cout << isomorphic(root1, root2);
}