class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
        int n=grid.size();
        int dis=1;
        if(grid[0][0]==1 or grid[n-1][n-1]==1)return -1;
        
        queue<int>q;
        q.push(0);
        
        while(q.size()){
            int qsize=q.size();
            while(qsize--){
                int idx=q.front();
                q.pop();
                int sr=idx/n,sc=idx%n;
                if(sr==n-1 and sc==n-1)return dis;
                for(auto d:dir){
                    int r=sr+d[0],c=sc+d[1];
                    if(r>=0 and c>=0 and r<n and c<n and grid[r][c]==0)
                    {
                        
                        q.push(r*n+c);
                            grid[r][c]=1;
                    }
                }
            }
            dis++;
        }
        
        return -1;
    }
};