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
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        
        return solve(1,cuts.size()-2,dp,cuts);
    }
};