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
	node*root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
void zigzag(node*root) {
	node*temp;
	stack<node*> s1, s2;
	s1.push(root);
	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) {
			temp = s1.top();
			s1.pop();
			cout << temp->data << " ";
			if (temp->left) {
				s2.push(temp->left);
			}
			if (temp->right) {
				s2.push(temp->right);
			}
		}
		while (!s2.empty()) {
			temp = s2.top();
			s2.pop();
			cout << temp->data << " ";
			if (temp->right) {
				s1.push(temp->right);
			}
			if (temp->left) {
				s1.push(temp->left);
			}
		}
	}
}
int main() {
	node*root = buildtree();
	// print(root);
	zigzag(root);
}