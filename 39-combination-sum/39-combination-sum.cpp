class Solution {
public: 
    vector<vector<int>>ans;
    void solve(int idx,int trg,vector<int>&cnd,vector<int>&ds){
        if(idx==cnd.size()){
            return;
        }
        if(trg==0){
            ans.push_back(ds);
            return;
        }
        if(trg-cnd[idx]>=0){
            ds.push_back(cnd[idx]);
            solve(idx,trg-cnd[idx],cnd,ds);
            ds.pop_back();
        }
        
        solve(idx+1,trg,cnd,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& cnd, int target) {
        vector<int>ds;
        solve(0,target,cnd,ds);
        return ans;
    }
};