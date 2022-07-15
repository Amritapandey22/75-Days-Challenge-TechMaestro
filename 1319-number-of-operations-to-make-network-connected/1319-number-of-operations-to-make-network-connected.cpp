class Solution {
public:
    vector<int>par;
    vector<int>size;
    int cycles=0;
    int findPar(int u){
        return par[u]==u?u:findPar(par[u]);
    }
    void merge(int u,int v){
        u=findPar(u);
        v=findPar(v);
        if(u!=v)par[u]=v;
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //you basically have to remove cycles
        if(n-1>connections.size())return -1;
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)par[i]=i;
        for(auto el:connections){
            merge(el[0],el[1]);
        }
        
        for(int i=0;i<n;i++)cycles+=par[i]==i;
        return cycles-1;
    }
};