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
	node* root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void postorderIterative(node*root) {
	stack<node*> stk;
	stk.push(root);
	stack<int>out;
	while (!stk.empty()) {
		node*curr = stk.top();
		stk.pop();
		out.push(curr->data());
		if (curr->left) {
			stk.push(curr->left);
		}
		if (curr->right) {
			stk.push(curr->right);
		}
	}
	while (!out.empty()) {
		cout << out.top() << " ";
		out.pop();
	}
}
void print(node* root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	print(root->right);
	cout << root->data << " ";
}
int main(){
	node*root = buildtree();
	print(root);
	postorderIterative(root);
}