class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        set<char>st;
        for(int i=0;i<s.size();i++){
          
            if(mp.find(s[i])==mp.end()){
               mp[s[i]]=t[i]; 
                st.insert(t[i]);
            }else{
                if(mp[s[i]]!=t[i])return false;
            }
        }
        
        return true and mp.size()==st.size();
    }
};