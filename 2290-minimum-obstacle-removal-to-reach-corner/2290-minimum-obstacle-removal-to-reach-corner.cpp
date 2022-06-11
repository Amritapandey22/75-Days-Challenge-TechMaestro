class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        //djisktra algo can be used 
        //also 01 bfs concept can be used,which is a cp thing but I understood it
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>dir={0,1,0,-1,0};
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        //{wt,{i,j}}
        
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto vtx=pq.top();
            pq.pop();
            
            int x=vtx.second.first;
            int y=vtx.second.second;
            int wsf=vtx.first;
            
           //ab direcn me ghumaao  chaaro taraf
            
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                
                if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
                 int curWt=grid[x][y]==1;
                
                if(wsf+curWt<dis[nx][ny]){
                    dis[nx][ny]=wsf+curWt;
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};