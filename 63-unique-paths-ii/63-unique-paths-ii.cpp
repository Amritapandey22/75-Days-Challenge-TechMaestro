class Solution {
public:
    int getPaths(int sr,int sc,int er,int ec,vector<vector<int>>dir,vector<vector<int>>&dp,vector<vector<int>>obGrid){
     for(int i=er;i>=sr;i--){
         for(int j=ec;j>=sc;j--){
             if(i==er and j==ec){
                 dp[i][j]=1;
                 continue;
             }
            long int count = 0;
                 for(auto d:dir){
                 int r=i+d[0],c=j+d[1];
                 if(r >= 0 and c >= 0 and r <= er and c <= ec and obGrid[r][c]==0) count+=dp[r][c];
             }
             
             dp[i][j]=count;
         }
     } 
        return dp[sr][sc];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obGrid) {
        int n= obGrid.size(),m=obGrid[0].size();
        if(obGrid[0][0]==1 or obGrid[n-1][m-1] == 1) 
           return 0;
        vector<vector<int>>dir;
        dir = {{0,1},{1,0}};
        vector<vector<int>>dp(n,vector<int>(m,0));
        return getPaths(0,0,n-1,m-1,dir,dp,obGrid);
        
    }
};