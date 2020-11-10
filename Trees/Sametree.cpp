 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL){
            return true;
        }
        if(p && q && p->val == q->val && isSameTree(p->left,q->left) and isSameTree(p->right,q->right)){
            return true;
        }
    
        return false;
}
 bool hasPathSum(TreeNode* root, int sum) {
         if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}