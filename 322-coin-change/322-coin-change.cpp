class Solution {
public:
    int solve(int idx,int trg,vector<int>& coins,vector<vector<int>>&dp){
        
        if(idx==0){
            if(trg%coins[0]==0) return trg/coins[0];
            return 1e9;
        }
        
        if(dp[idx][trg]!=-1)return dp[idx][trg];
        
        int nt=0+solve(idx-1,trg,coins,dp);
        int t=1e9;
        if(coins[idx]<=trg)t=1+solve(idx,trg-coins[idx],coins,dp);
        
        return dp[idx][trg]=min(nt,t);
    }
    int coinChange(vector<int>& coins, int trg) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(trg+1,-1));
        int ans=solve(n-1,trg,coins,dp);
        
        return ans==1e9?-1:ans;
    }
};