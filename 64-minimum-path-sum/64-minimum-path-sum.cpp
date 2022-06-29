class Solution {
public:
//     int solve(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
//         //base case
//         if(i==0 and j==0)return dp[i][j]=grid[i][j];
//         if(i<0 or j<0)return 1e8;
        
//         if(dp[i][j]!=-1)return dp[i][j];
//         int up=grid[i][j]+solve(i-1,j,dp,grid);
//         int left=grid[i][j]+solve(i,j-1,dp,grid);
        
//         return dp[i][j]=min(up,left);
        
//     }
    int minPathSum(vector<vector<int>>& grid) {
        //n-1,m-1 -->0,0..............normal sarkari tareeka,s=damn easy question
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                int up=1e8;
                int left=1e8;
                
                if(i>0)up=grid[i][j]+dp[i-1][j];
                if(j>0)left=grid[i][j]+dp[i][j-1];
                
                dp[i][j]=min(up,left);
            }
        }
        return dp[n-1][m-1];
        
        
    }
};