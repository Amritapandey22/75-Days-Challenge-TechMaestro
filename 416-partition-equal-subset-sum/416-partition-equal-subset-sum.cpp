class Solution {
public:
    bool solve(int i,int trg,vector<vector<int>>&dp,vector<int>& nums){
        if(trg==0)return true;
        if(i==0)return dp[i][trg]=nums[0]==trg;
        
        if(dp[i][trg]!=-1)return dp[i][trg];
        int notpick=solve(i-1,trg,dp,nums);
        int pick=false;
        if(nums[i]<=trg)pick=solve(i-1,trg-nums[i],dp,nums);
        
        return dp[i][trg]=pick or notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int el:nums)sum+=el;
        if(sum%2==1)return false;
        int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
        int trg=sum/2;
        return solve(n-1,trg,dp,nums); 
    }
};