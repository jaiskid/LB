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
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
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
void InorderIterative(node* root) {
	stack<node*> s;
	node *curr = root;
	while (!s.empty() || curr != NULL) {
		if (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}
		else {
			curr = s.top();
			s.pop();
			cout << curr->data << " ";
			curr = curr->right;
		}
	}
}
int main() {
	node*root = buildtree();
	InorderIterative(root);
}