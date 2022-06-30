class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        //this is space consuming approach
        vector<int>frq(26,0);
        frq[kp[0]-'a']=rt[0];
        
        for(int i=1;i<rt.size();i++){
            char ch=kp[i];
            int dur=rt[i]-rt[i-1];
            frq[ch-'a']=max(frq[ch-'a'],dur);
        }
        char ans;
        int maxi=0;
        for(int i=0;i<26;i++){
           if(frq[i]>=maxi){
               maxi=frq[i];
               ans=i+'a';
           } 
        }
        
        return ans;
    }
};