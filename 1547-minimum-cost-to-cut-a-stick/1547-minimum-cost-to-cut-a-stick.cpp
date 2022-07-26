class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>& cuts){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=1e9;
        for(int cut=i;cut<=j;cut++){
            int cost=cuts[j+1]-cuts[i-1]+solve(i,cut-1,dp,cuts)+solve(cut+1,j,dp,cuts);
            mini=min(cost,mini);
        }
        
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        
        for(int i=c-2;i>=1;i--){
            for(int j=1;j<=c-2;j++){
                if(i>j)continue;
                  int mini=1e9;
                    for(int cut=i;cut<=j;cut++){
                        int cost=cuts[j+1]-cuts[i-1]+dp[i][cut-1]+dp[cut+1][j];
                        mini=min(cost,mini);
                    }
        
         dp[i][j]=mini;
                
            }
        }
        
        return dp[1][c-2];
    }
};