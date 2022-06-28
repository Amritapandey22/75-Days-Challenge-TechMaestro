class Solution {
public:
    int dp[70][70][70]={};
    int solve(int i,int j1,int j2,vector<vector<int>>& grid){
        if(j2<0 or j2>=grid[0].size() or j1<0 or j1>=grid[0].size())return -1e9;
        
        if(i==grid.size()-1){
            if(j1==j2)return dp[i][j1][j2]=grid[i][j2];
            else return dp[i][j1][j2]=grid[i][j2]+grid[i][j1];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=-1e9;
        for(int c1=-1;c1<=1;c1++){
            for(int c2=-1;c2<=1;c2++){
                int value=0;
                if(j1==j2)value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                
                value+=solve(i+1,j1+c1,j2+c2,grid);
                maxi=max(maxi,value);
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp, -1, sizeof(dp));
        //vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        int maxi=-1e9;
        return solve(0,0,m-1,grid);
    }
};