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
void generateArray(node*root, int *ancestor) {
	ancestor[root->data] = -1;
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node*temp = q.front();
		q.pop();
		if (temp->left) {
			ancestor[temp->left->data] = temp->data;
			q.push(temp->left);
		}
		if (temp->right) {
			ancestor[temp->right->data] = temp->data;
			q.push(temp->right);
		}
	}
}
int kthAncestor(node*root, int n, int k, int nod) {
	int ancestor[n + 1] = {0};
	generateArray(root, ancestor);
	int count = 0;
	while (nod != -1) {
		nod = ancestor[nod];
		count++;
		if (count == k)
			break;
	}
	return nod;
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
int main() {
	node*root = buildtree();
	int n;
	cin >> n;
	int k;
	cin >> k;
	int nod;
	cin >> nod;
	cout << kthAncestor(root, n, k, nod);
}