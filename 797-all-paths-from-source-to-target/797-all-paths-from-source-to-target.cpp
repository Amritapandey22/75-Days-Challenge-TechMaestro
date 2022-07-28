class Solution {
public:
    vector<vector<int>>res;
    vector<int>ans;
    int trg=0;
    void solve(int src,vector<bool>&vis,vector<vector<int>>& graph){
        
        ans.push_back(src);
        if(src==trg){
            res.push_back(ans);
            //return;
        }
        else for(auto it:graph[src]){
            solve(it,vis,graph);
        }
       //cout<<src<<endl;
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        trg=n-1;
        vector<bool>vis(n,false);
        
         solve(0,vis,graph);
        return res;
    }
};