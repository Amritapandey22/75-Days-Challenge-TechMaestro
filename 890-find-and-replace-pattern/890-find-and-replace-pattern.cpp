class Solution {
public:
    bool matchStr(string &s,string &t){
        unordered_map<char,char>smp,tmp;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            char sch=s[i];
            char tch=t[i];
            if(smp.count(sch) and smp[sch]!=tch){
                return false;
            }
            else if(tmp.count(tch) and tmp[tch]!=sch)return false;
            else{
                smp[sch]=tch;
                tmp[tch]=sch;
            }
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>ans;
        
        for(auto wrd:words){
            if(matchStr(wrd,pattern))ans.push_back(wrd);
        }
        
        return ans;
    }
};