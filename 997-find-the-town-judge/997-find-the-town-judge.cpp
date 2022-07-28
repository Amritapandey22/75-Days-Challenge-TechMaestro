class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 )return n==1?1:-1;
        vector<int>indeg(n+1,0),outdeg(n+1,0);
        
        for(auto it:trust){
            int a=it[0];
            int b=it[1];
            
            outdeg[a]+=1;
            outdeg[b]-=1;
        }
        int ans=-1*(n-1);
        for(int i=0;i<=n;i++){
            if(outdeg[i]==ans)return i;
        }
        
        return -1;
    }
};