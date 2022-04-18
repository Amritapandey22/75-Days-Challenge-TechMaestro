class Solution {
public:
    int kthSmallest(TreeNode* root, int k){
        if(!root)return -1;
        int L = kthSmallest(root->left,k);
        if(L!=-1)return L;
        pos+=1;
        if(pos==k)return root->val;
        int R = kthSmallest(root->right,k);
        if(R!=-1)return R;
        return -1;
    }
    
    
    int pos = 0;
};