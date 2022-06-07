class Solution {
public:
    bool isPalindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        
        return true;
    }
    void solve(string &s,int idx,vector<string>&ds,vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.size();i++){
           if(isPalindrome(s,idx,i)){
               ds.push_back(s.substr(idx,i-idx+1));
               solve(s,i+1,ds,ans);
               ds.pop_back();
           }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(s,0,ds,ans);
        
        return ans;
    }
};