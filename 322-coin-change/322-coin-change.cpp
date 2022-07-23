class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,0));
        //i-1 or trg-a[i]
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int idx=1;idx<n;idx++){
            for(int trg=0;trg<=amt;trg++){
                    int nt=0+dp[idx-1][trg];
                    int t=1e9;
                    if(coins[idx]<=trg)t=1+dp[idx][trg-coins[idx]];

                     dp[idx][trg]=min(nt,t);
            }
        }
        
        return dp[n-1][amt]==1e9?-1:dp[n-1][amt];
    }
};