class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ht) {
        
        //distance array
        int n=ht.size();
        int m=ht[0].size();
        
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        
        priority_queue<vector<int>>pq;
        dis[0][0]=0;
        pq.push({0,0,0});
        
        vector<vector<int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
        
        while(pq.size()){
            auto node=pq.top();
            pq.pop();
            int wt=-node[0];
            int xc=node[1];
            int yc=node[2];
            
            if(xc==n-1 and yc==m-1)return -node[0];
            //dis[xc][yc]=-1;
            for(auto d:dir){
                int nr=xc+d[0];
                int nc=yc+d[1];
                
                if(nr>=0 and nc>=0 and nr<n and nc<m)
                   {
                    int nwt=max(wt,abs(ht[xc][yc]-ht[nr][nc]));
                    if(dis[nr][nc]>nwt){
                         dis[nr][nc]=nwt;
                         pq.push({-nwt,nr,nc});
                    }
                       
                }
            }
        }
        
        return -1;
    }
};