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

vector<int>v;
string inorder(Node* node, unordered_map<string, int>& m)
{
	if (!node)
		return "";

	string str = "(";

	str += inorder(node->left, m);
	str += to_string(node->data);
	str += inorder(node->right, m);

	str += ")";

	// Subtree already present (Note that we use
	// unordered_map instead of unordered_set
	// because we want to print multiple duplicates
	// only once, consider example of 4 in above
	// subtree, it should be printed only once.
	if (m[str] == 1)
		v.push_back(node->data);

	m[str]++;

	return str;
}

// Wrapper over inorder()
void printAllDups(Node* root)
{	v.clear();
	unordered_map<string, int> m;
	inorder(root, m);
	sort(v.begin(), v.end());
	if (v.size() == 0) {
		cout << -1;
		return;
	}
	for (auto val : v) {
		cout << val << " ";
	}
}
int main() {
	node*root = buildtree();
	printAllDups(root);

}