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
	node* root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void diagonal(node*root) {
	if (root == NULL) {
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node*temp = q.front();
		q.pop();
		if (temp == NULL) {
			if (q.empty())
				return;
			cout << endl;
			q.push(NULL);
		}
		else {
			while (temp) {
				cout << temp->data << " ";
				if (temp->left)
					q.push(temp->left);
				temp = temp->right;
			}
		}
	}
}
int main() {
	node*root = buildtree();
	diagonal(root);
}