class Solution {
public:
    int countSubstrings(string s) {
    int n=s.length(),count=0;

 vector<vector<bool>>dp(n,vector<bool>(n));
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            //cout<<i;
            if(gap==0)dp[i][j]=true;
            else if(gap==1 and s[i]==s[j]){
                dp[i][j]=true;
            }else {
                dp[i][j]= s[i]==s[j] and dp[i+1][j-1];
            }
            
            if(dp[i][j]) count++;
        }
    }
        
        return count;
    }
};