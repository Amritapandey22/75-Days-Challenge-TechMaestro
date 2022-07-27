class Solution {
public:
    vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& grid,int sr,int sc){
        grid[sr][sc]='*';
        
        for(auto d:dir){
            int r=sr+d[0],c=sc+d[1];
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r]                              [c]=='1')
                dfs(grid,r,c);
        }        
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    cnt+=1;
                }
            }
        }
        
        return cnt;
    }
};