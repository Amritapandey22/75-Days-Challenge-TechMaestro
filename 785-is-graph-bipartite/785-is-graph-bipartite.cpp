class Solution {
public:
    bool isBipCheck(vector<vector<int>>& graph,int src,vector<int>&vis){
        queue<int>q;
        q.push(src);
        int color=1;
        vis[src]=color;
        
        while(q.size()){
            int n=q.size();
            while(n--){
            int vtx=q.front();
            q.pop();
            if(vis[vtx]!=-1 and vis[vtx]!=color)return false;
            vis[vtx]=color;
            for(int el:graph[vtx]){
                if(vis[el]==-1)q.push(el);
            }
        }
            color=(color+1)%2;
        }
        
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++){
            if(vis[i]==-1 and isBipCheck(graph,i,vis)==false) return false;
        }
        
        return true;
    }
};