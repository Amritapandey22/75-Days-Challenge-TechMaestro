class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        int ans=0;
        int idx=0;
        
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0)dp[i][j]=true;
                else if(gap==1)dp[i][j]=s[i]==s[j];
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]){
                        dp[i][j]=true;                     
                        
                    }
                }
                
            }
        }
       string str="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len=j-i+1;
                if(dp[i][j] and len>ans){
                    ans=len;
                    str=s.substr(i,len);
                }
            }
        }
        
        return str;
    }
};