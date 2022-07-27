class Solution {
public:
     vector<int>result;
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,int src){
        vis[src]=1;
        bool ans=false;
        for(auto it:graph[src]){
            if(vis[it]==0){
              ans=dfs(graph,vis,it);
              if(ans)return true;  
            }
            
            if(vis[it]==1)return true;//cycle exists
            
            
        }
        vis[src]=2;
        result.push_back(src);
        return false;
        
    }
    vector<int> findOrder(int n, vector<vector<int>>& prq) {
           vector<int>vis(n,0);
        //0-not visit 1-in current cycle,2-just visited
        
        //1->0
        vector<vector<int>>graph(n);
        for(auto vec:prq){
            graph[vec[0]].push_back(vec[1]);
        }
        
        bool ans=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans=ans or dfs(graph,vis,i);
            }
        }
        
        if(ans)result.clear();
        return result;
    }
};