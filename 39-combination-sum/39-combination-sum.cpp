class Solution {
public:
    void solve(int idx,vector<int>& cnd, int trg,vector<int>&ds,vector<vector<int>>&ans){
        if(idx==cnd.size()){
            if(trg==0){
                ans.push_back(ds);                
            }
            return;
        }
        
        if(trg-cnd[idx]>=0){
            ds.push_back(cnd[idx]);
            solve(idx,cnd,trg-cnd[idx],ds,ans);
            ds.pop_back();
        }
        solve(idx+1,cnd,trg,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& cnd, int trg) {
         vector<vector<int>>ans;
        vector<int>ds;
        solve(0,cnd,trg,ds,ans);
        return ans;
    }
};