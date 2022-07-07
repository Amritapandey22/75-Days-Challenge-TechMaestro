class Solution {
public:
    //s2-j,s1-i
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 and j<0)return 0;
        if(i<0 and j>=0){
            int ans=0;
            for(int ii=0;ii<=j;ii++)ans+=(int)(s2[ii]);
            return ans;
        }
        if(j<0 and i>=0){
            int ans=0;
            for(int ii=0;ii<=i;ii++)ans+=(int)(s1[ii]);
            return ans;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j])return dp[i][j]=0+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=min((int)s2[j]+solve(i,j-1,s1,s2,dp),
                              (int)s1[i]+solve(i-1,j,s1,s2,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s1,s2,dp);
        
    }
};