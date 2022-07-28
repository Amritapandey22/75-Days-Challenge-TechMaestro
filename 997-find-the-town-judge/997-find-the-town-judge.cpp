class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 )return n==1?1:-1;
        vector<int>indeg(n+1,0),outdeg(n+1,0);
        
        for(auto it:trust){
            int a=it[0];
            int b=it[1];
            
            outdeg[a]+=1;
            indeg[b]+=1;
        }
        
        for(int i=0;i<=n;i++){
            if(indeg[i]==n-1 and outdeg[i]==0)return i;
        }
        
        return -1;
    }
};