class Solution {
public:
    int solve(int idx,vector<int>& arr,vector<int>&dp){
    if(idx==0)return arr[idx];
    if(idx<0)return 0;
    
    if(dp[idx]!=-1)return dp[idx];
    
    int notTake=0+solve(idx-1,arr,dp);
    int take=arr[idx]+solve(idx-2,arr,dp);
    
    
    return dp[idx]=max(take,notTake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        
        return solve(n-1,nums,dp);
    }
};