class Solution {
public:
    /*class Solution {
public:
    int getLIS(int ei,vector<int>& dp,vector<int>& nums){
        if(dp[ei] != 0)return dp[ei];
        int maxval=1;
        for(int i=ei+1;i<nums.size();i++){
            if(nums[i]>nums[ei]){
                int recL=getLIS(i,dp,nums);
                maxval=max(maxval,recL+1);
            }
        }
        
        return dp[ei]=maxval;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            int temp=getLIS(i,dp,nums);
            ans=max(ans,temp);
        }
        return ans;       
    }
};*/
    int getLIS(int i,vector<int>& nums,vector<int>& dp){
        if(dp[i]!=-1)return dp[i];
        
        int ans=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ans=max(ans,getLIS(j,nums,dp)+1);
            }
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=1;
        
        for(int i=0;i<n;i++){
            ans=max(ans,getLIS(i,nums,dp));
        }
        
        return ans;
    }
};