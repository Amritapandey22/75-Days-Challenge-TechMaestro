class Solution {
public:
    void solve(vector<int>&ds,vector<vector<int>>&ans,int idx,vector<int>&nums){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        solve(ds,ans,idx+1,nums);
        ds.pop_back();
        solve(ds,ans,idx+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(ds,ans,0,nums);
        
        return ans;
    }
};