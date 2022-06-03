class Solution {
public:
    void solve(int idx,vector<bool>&check,vector<int>&nums,vector<int>&ds,
        vector<vector<int>>&ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
        }
        
        for(int i=0;i<nums.size();i++){
            if(!check[i]){
                check[i]=true;
                ds.push_back(nums[i]);
                solve(i+1,check,nums,ds,ans);
                ds.pop_back();
                check[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>check(n,false);
        vector<int>ds;
        vector<vector<int>>ans;
        
        solve(0,check,nums,ds,ans);
        
        return ans;
    }
};