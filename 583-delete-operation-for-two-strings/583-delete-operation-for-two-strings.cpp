class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 or j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=max(solve(i,j-1,s1,s2,dp),solve(i-1,j,s1,s2,dp));
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<int>prev(m+1,0),curr(m+1,0);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//               if(s1[i-1]==s2[j-1])curr[j]=1+prev[j-1];
//                 else curr[j]=max(curr[j-1],prev[j]);
//             }
            
//             prev=curr;
//         }
        int len=solve(n-1,m-1,s1,s2,dp);
       // cout<<len;
        return (n+m-2*len);
    }
};