class Solution {
public:
    //i->j
    int solve(int i,int j,string &s1, string &s2,vector<vector<int>>&dp){
        if(i==0 and j!=0)return j;//insert all the chars of word2 to word1
        if(i!=0 and j==0)return i;
        if(i==0 and j==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i-1]==s2[j-1]) return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=1+min(solve(i-1,j-1,s1,s2,dp),min(solve(i,j-1,s1,s2,dp),solve(i-1,j,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(n,m,word1,word2,dp);
    }
};