class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int sr,int sc,vector<vector<int>>& grid){
        grid[sr][sc]=0;
        
        int count=0;
        for(auto d:dir){
            int r=sr+d[0];
            int c=sc+d[1];
            
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]==1){
                count+=dfs(r,c,grid);
            }
        }
        
        return count+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0,maxSize=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    ans=dfs(i,j,grid);         
                    //cout<<maxSize<<endl;
                maxSize=max(ans,maxSize);
                }
            }
        }
        
        return maxSize;
    }
};