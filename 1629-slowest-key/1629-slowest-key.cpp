class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        int diff=rt[0];
        char key=kp[0];
        
        for(int i=1;i<rt.size();i++){
            if(rt[i]-rt[i-1]==diff){
                key=max(key,kp[i]);
            }else if(rt[i]-rt[i-1]>diff){
                diff=rt[i]-rt[i-1];
                key=kp[i];
            }
        }
        
        return key;
    }
};