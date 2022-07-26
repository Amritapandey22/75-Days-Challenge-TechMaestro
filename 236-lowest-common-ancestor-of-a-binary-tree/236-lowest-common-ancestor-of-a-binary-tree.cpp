/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA;
    bool getLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)return false;
        bool selfpres=(root == p or root ==q);
        bool leftpres=getLCA(root->left,p,q);
        bool rightpres=getLCA(root->right,p,q);
        
        if((rightpres and leftpres) or (rightpres and selfpres) or (selfpres and leftpres))
            LCA = root;
        
        return leftpres or rightpres or selfpres;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getLCA(root,p,q);
        return LCA;
    }
};