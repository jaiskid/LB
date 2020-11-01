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
	root->right = buildtree();
	return root;
}
void leftviewRec(node*root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}
	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}
	leftviewRec(root->left, level + 1, maxlevel);
	leftviewRec(root->right, level + 1, maxlevel);
}
void leftView(node*root) {
	int maxlevel = 0;
	leftviewRec(root, 1, maxlevel);
}
int main() {
	node*root = buildtree();
	leftView(root);
}