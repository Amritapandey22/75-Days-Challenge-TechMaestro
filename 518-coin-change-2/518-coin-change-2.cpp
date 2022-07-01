class Solution {
public:
    int solve(int idx,int trg,vector<int>& coins,vector<vector<int>>& dp){
        if(idx==0){
            return trg%coins[idx]==0;
        }
        
        if(dp[idx][trg]!=-1)return dp[idx][trg];
        
        int nt=solve(idx-1,trg,coins,dp);
        int take =0;
        if(coins[idx]<=trg)take=solve(idx,trg-coins[idx],coins,dp);
        
        return dp[idx][trg]=take+nt;
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        
        return solve(n-1,amt,coins,dp);
    }
};