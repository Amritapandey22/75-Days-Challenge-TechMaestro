class Solution {
public:
    
    string shortestCommonSupersequence(string s1, string s2) {
         int n=s1.size();
         int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //LCS
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       
     
       
        string ans="";
        while(n>0 and m>0){
            if(s1[n-1]==s2[m-1]){
               ans+=s1[n-1];
                
                n--;
                m--;
            }
            else if(dp[n-1][m]>dp[n][m-1]){
                ans+=s1[n-1];
                n--;
            }
            else{
                ans+=s2[m-1];
                m--;
            }
            
            //cout<<ans<<endl;
        }
        
        
        while(n>0){
            ans+=s1[n-1];
            
            n--;
        }
        while(m>0){
            ans+=s2[m-1];
            
            m--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};