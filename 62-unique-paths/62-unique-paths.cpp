class Solution {
public:
//     int solve(int i,int j,vector<vector<long>>dp){
//         //base case
//         if(i<0 or j<0)return 0;
//         if(i==0 and j==0)return 1;
        
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
        
//         return dp[i][j]=solve(i-1,j,dp)+solve(i,j-1,dp);
//     }
    int uniquePaths(int n, int m) {
        vector<vector<long>>dp(n,vector<long>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                int count=0;
                if(i>0)count+=dp[i-1][j];
                if(j>0)count+=dp[i][j-1];
                
                dp[i][j]=count;
            }
        }
        
        return dp[n-1][m-1];
    }
};