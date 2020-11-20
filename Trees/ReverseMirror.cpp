#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left, *right;
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
void LevelOrder(node*root) {
	queue<node*>q;
	q.push(root);
	stack<node*>S;
	while (!q.empty()) {
		node*temp = q.front();
		q.pop();
		S.push(temp);

		if (temp->right) {
			q.push(temp->right);
		}
		if (temp->left) {
			q.push(temp->left);
		}


	}
	while (!S.empty()) {
		cout << S.top()->data << " ";
		S.pop();
	}
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
int main() {
	node*root = NULL;
	root = buildtree();
	print(root);
	cout << endl;
	LevelOrder(root);
}