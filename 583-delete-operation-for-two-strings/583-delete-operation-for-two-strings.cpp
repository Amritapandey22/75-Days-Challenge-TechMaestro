class Solution {
public:
     int getLCS(int n,int m,string &t1, string &t2,vector<vector<int>>&dp){
        if(n==0 or m==0)return dp[n][m]=0;
        if(dp[n][m]!=-1)return dp[n][m];
        
        int a=getLCS(n-1,m-1,t1,t2,dp);
        int b=getLCS(n-1,m,t1,t2,dp);
        int c=getLCS(n,m-1,t1,t2,dp);
        
        if(t1[n-1]==t2[m-1])return dp[n][m]=a+1;
        else return dp[n][m]=max(b,c);
    }
    int minDistance(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return n+m-2*getLCS(n,m,text1,text2,dp);
        
    }
};