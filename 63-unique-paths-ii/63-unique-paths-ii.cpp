class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& og){
        if(i<0 or j<0)return 0;
        if(og[i][j]==1)return 0;
        if(i==0 and j==0)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(i-1,j,dp,og)+solve(i,j-1,dp,og);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        
        int n=og.size();
        int m=og[0].size();
        if(n==1 and m==1 and og[0][0]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(og[0][0]==1)return 0;
        dp[0][0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                int count=0;
                if(i>0 and og[i][j]!=1)count+=dp[i-1][j];
                if(j>0 and og[i][j]!=1)count+=dp[i][j-1];
                
                dp[i][j]=count;
            }
        }
        
        return dp[n-1][m-1];
    }
};