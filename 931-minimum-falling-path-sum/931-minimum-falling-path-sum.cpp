class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& mt,vector<vector<int>>& dp){
        if(j<0 or j>=mt[0].size())return 1e9;
        
        if(i==0)return dp[i][j]=mt[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int up=mt[i][j]+solve(i-1,j,mt,dp);
        int ld=mt[i][j]+solve(i-1,j-1,mt,dp);
        int rd=mt[i][j]+solve(i-1,j+1,mt,dp);
        
        return dp[i][j]=min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& mt) {
        int n=mt.size();
        int m=mt[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int mini=1e9;
        
        for(int j=0;j<m;j++){
            mini=min(mini,solve(n-1,j,mt,dp));
        }
        
        return mini;
                             
    }
};