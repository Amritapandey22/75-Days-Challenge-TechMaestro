class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        
        int maxi=1;
        vector<int>dp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0] and dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            
            maxi=max(maxi,dp[i]);
        }
        
        return maxi;
    }
};