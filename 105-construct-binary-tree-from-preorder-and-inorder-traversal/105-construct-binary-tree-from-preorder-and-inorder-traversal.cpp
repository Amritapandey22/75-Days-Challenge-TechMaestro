
class Solution {
public:
    TreeNode* buildHelper(vector<int>& pre, vector<int>& in,int preS , int preE , int inS ,int inE){
        if(preS > preE )return nullptr;
        
        int rootdata = pre[preS];
        int rootidx=0;
        for(int i = inS; i<= inE;i++){
            if(in[i] == rootdata) {
                rootidx = i;
                break;
            }
        }
        
        int LpreS = preS +1;
        int LinE = rootidx-1;
        int RinS = rootidx+1;
        int RpreE = preE;
        int LinS = inS;    
        int RinE = inE;
        int LpreE = LinE - LinS + LpreS;
        int RpreS = LpreE+1;
        
        TreeNode* root = new TreeNode(rootdata);
        root->left = buildHelper(pre,in,LpreS,LpreE,LinS,LinE);
        root->right = buildHelper(pre,in,RpreS,RpreE,RinS,RinE);
        return root;     
               
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        if(n==1){
          TreeNode* root = new TreeNode(pre[0]);
            return root;
        }
        
        return buildHelper(pre,in,0,n-1,0,n-1);
        
    }
};