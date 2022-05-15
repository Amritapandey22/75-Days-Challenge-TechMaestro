
class Solution {
public:
    void dfshelper(TreeNode* root,int n,int &h,int &sum){
        if(root==nullptr) return;
        if(n==h) sum+=root->val;
        if(n>h){
            sum=root->val;
            h=n;
        }
        
        dfshelper(root->left,n+1,h,sum);
        dfshelper(root->right,n+1,h,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root->left == nullptr and root->right == nullptr) return root->val;
        int sum=0 , h=1;
        dfshelper(root,1,h,sum);
        return sum;
        
        
    }
};