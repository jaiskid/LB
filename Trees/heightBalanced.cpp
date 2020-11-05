
#include<bits/stdc++.h>
using namespace std;
class node
{
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
int height(node* root, bool &flag) {
    if (!root) return 0;

    int l = height(root->left, flag);
    int r = height(root->right, flag);
    if (abs(l - r) > 1) flag = false;
    return 1 + max(l, r);
}

bool isBalanced(node *root)
{
    bool flag = true;
    int h = height(root, flag);
    return flag;
}
int main() {
    node*root = buildtree();
    cout << isBalanced(root);
}
