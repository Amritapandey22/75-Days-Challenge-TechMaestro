/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
    
public:
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        if(prev!=NULL and root->val<prev->val){
            if(!first){
                //first violation
                first=prev;
                mid=root;
            }else last=root;
        }
        
        prev=root;
        inorder(root->right);
    }
     void recoverTree(TreeNode* root) {
      first=mid=last=prev=NULL;
         inorder(root);
         if(first and last)swap(first->val,last->val);
         else swap(first->val,mid->val);
    }
};