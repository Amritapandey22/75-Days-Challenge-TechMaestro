class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int si=0,ei=0,n=s.size(),len=0;
        if(n==0)return 0;
        bool count = false;
        vector<int>frq(128,0);
        while(ei<n){
            if(frq[s[ei]]==1)count=true;
            frq[s[ei]]++;
            ei++;
            
            while(count){
                if(frq[s[si]]==2)count=false;
                
                frq[s[si]]--;
                si++;
            }
            
            len=max(len,ei-si);
        }
        
        return len;
        
    }
};