class Solution {
public:
    int solve(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        if(i==0 or j==0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i-1]==t2[j-1]) return dp[i][j]=1+solve(i-1,j-1,t1,t2,dp);
        
        //this means we are skipping the letters
        return dp[i][j]=max(solve(i,j-1,t1,t2,dp),solve(i-1,j,t1,t2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(n,m,text1,text2,dp);
    }
};