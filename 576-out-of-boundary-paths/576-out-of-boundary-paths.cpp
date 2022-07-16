class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int mod = (int) 1e9 + 7;
    int findpathsB(int n,int m,int k,int sr,int sc,vector<vector<vector<int>>>&dp){
        if(sr<0 or sc<0 or sr>=n or sc>=m)return 1;
        
        if(k==0)return dp[sr][sc][k]=0;
        if (dp[sr][sc][k] != -1)
            return dp[sr][sc][k];
        int count=0;
        for(auto d:dir){
            int r=sr+d[0],c=sc+d[1];
            count=(count+findpathsB(n,m,k-1,r,c,dp))%mod;
        }
        
        return dp[sr][sc][k]=count;
    }
    int findPaths(int n, int m, int k, int sr, int sc) {
      vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1))); 
        return findpathsB(n,m,k,sr,sc,dp);
    }
};