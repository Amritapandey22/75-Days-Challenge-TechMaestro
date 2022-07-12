class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>frq(26);
        for(char ch:s)frq[ch-'a']++;
        for(int i=0;i<s.size();i++){
            if(frq[s[i]-'a']==1)return i;
        }
        
        return -1;
    }
};