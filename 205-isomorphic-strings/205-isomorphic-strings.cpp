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
    /*
    //amazing solution 
    
     bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
    
    */
};