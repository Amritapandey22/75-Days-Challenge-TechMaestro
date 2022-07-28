class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1)return -1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=-1;
        int level=0;
        vector<vector<int>>dir{{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
        while(q.size()){
            int sz=q.size();
            level+=1;
            while(sz--){
                auto node=q.front();
                q.pop();
                int xc=node.first;
                int yc=node.second;
                if(xc==n-1 and yc==m-1)return level;
                for(auto d:dir){
                    int x=xc+d[0];
                    int y=yc+d[1];
                    if(x>=0 and x<n and y>=0 and y<m and grid[x][y]==0){
                        q.push({x,y});
                        grid[x][y]=-1;
                    }
                }
            }
         
        }
        
        return -1;
    }
};