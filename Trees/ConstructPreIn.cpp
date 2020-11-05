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
int search(int *in, int start, int end, int value) {
	int i;
	for (i = start; i <= end; i++) {
		if (in[i] == value) {
			break;
		}
	}
	return i;
}
node* construct(int *pre, int *in , int start, int end) {
	static int preindex = 0;
	if (start > end) {
		return NULL;
	}

	node *root = new node(pre[preindex++]);
	if (start == end) {
		return root;
	}
	int index = search(in, start, end, root->data);
	root->left = construct(pre, in, start, index - 1);
	root->right = construct(pre, in, index + 1, end);
	return root;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	
	print(root->right);
	cout << root->data << " ";
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int pre[n];
	int	in[n];
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	node* root = construct(pre, in, 0, n - 1);
	print(root);
	return 0;
}