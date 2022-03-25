class Solution {
public:
     vector<int>par;
    vector<int>disc;
    vector<int>low;
    vector<bool>vis;
    int time=1;
    vector<vector<int>>st;
    void artEdgeCalc(vector<vector<int>>&graph,int u){
        low[u]=disc[u]=time;
        time+=1;
        vis[u]=true;
        for(int v:graph[u]){
           if(par[u]==v)continue;
           else if(vis[v]==true){
               low[u]=min(low[u],disc[v]);
           }else{
               par[v]=u;
               artEdgeCalc(graph,v);
               low[u]=min(low[u],low[v]);
               
               if(low[v]>disc[u]){
                   //articulation bridge
                   
                       
                   st.push_back({v,u});
                   //st.insert({u,v});
               }
           }
        }
        
       
    }
    
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& adj) {
         par.resize(V);
        
        disc.resize(V);
        low.resize(V);
        vis.resize(V);
        vector<vector<int>>graph(V);
        
        for(auto el:adj){
            int u=el[0];
            int v=el[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
         artEdgeCalc(graph,0);
          return st;
    }
};