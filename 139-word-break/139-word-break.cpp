class Solution {
public:
     bool solver(int i,string &str,unordered_set<string>st,vector<int>&dp){
       if(i==str.size())return true;
       if(dp[i]!=-1)return dp[i];
       string temp="";
       bool ans=false;
       for(int j=i;j<str.size();j++){
           temp+=str[j];
           if(st.find(temp)!=st.end() and solver(j+1,str,st,dp)) ans=true;
       }
       
       return dp[i]=ans;
    }
    int wordBreak(string str, vector<string> &B) {
        //code here
        unordered_set<string>st;
        int maxlen=0;
        for(auto s:B){
            st.insert(s);
            //maxlen=max(maxle,s.size());
        }
        vector<int>dp(str.size(),-1);
        return solver(0,str,st,dp);
    }
};