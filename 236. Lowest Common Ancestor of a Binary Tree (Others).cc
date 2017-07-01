class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* pleft = lowestCommonAncestor(root->left, p, q);
        TreeNode* pright = lowestCommonAncestor(root->right, p, q);
        return pleft==NULL? pright : pright==NULL ? pleft : root;
    }
};
