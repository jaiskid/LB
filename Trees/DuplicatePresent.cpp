#include<bits/stdc++.h>
using namespace std;
class node {
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
string preorder(node* root, unordered_map<string, int> &mp)
{
    string s;
    if (!root)
    {
        s += "$";
        return s;
    }
    s += root->data;
    s += preorder(root->left, mp);
    s += preorder(root->right, mp);
    mp[s]++;
    return s;
}
bool dupSub(node *root)
{
    unordered_map<string, int> mp;
    preorder(root, mp);
    for (auto i : mp)
        if (i.second >= 2 && i.first.length() > 3)
            return true;
    return false;
}
int main(int argc, char const *argv[])
{
    node*root = buildtree();
    cout << dupSub(root);
    return 0;
}