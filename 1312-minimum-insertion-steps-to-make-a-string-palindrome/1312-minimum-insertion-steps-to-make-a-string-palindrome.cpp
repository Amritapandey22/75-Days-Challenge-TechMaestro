class Solution {
public:
//     int solve(int i,int j,string &s,vector<vector<int>>&dp){
     
//         if(i==j)return 1;
//         if(i>j) return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(s[i]==s[j]) return dp[i][j]=2+solve(i+1,j-1,s,dp);
         
//         return dp[i][j]=max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
       
//     }
    
    int minInsertions(string s) {
        int i=0;
        int n=s.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                  if(i>=j){
                      dp[i][j]=(i==j)?1:0;
                      continue;
                  }
                  //Akku2507@
                  if(s[i]==s[j]){
                      dp[i][j]=2+dp[i+1][j-1];
                  }else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        
        
        return n-dp[0][n-1];
    }
};