class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& grid,int i,int j){
        if(i==0 and j==0){
            return dp[i][j]=grid[i][j];
        }
        //cout<<i<<endl;
        if(i<0 or j<0) {
            //cout<<"aaya";
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int up=grid[i][j]+solve(dp,grid,i-1,j);
        int left=grid[i][j]+solve(dp,grid,i,j-1);
        
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
     
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(dp,grid,n-1,m-1);
        return dp[n-1][m-1];
    }
};