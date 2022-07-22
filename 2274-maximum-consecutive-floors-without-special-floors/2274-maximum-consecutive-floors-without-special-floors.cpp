class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) {
        sort(sp.begin(),sp.end());
        int ans=0;
        ans=max(sp[0]-bottom,ans);
        ans=max(top-sp[sp.size()-1],ans);
        
        for(int i=1;i<sp.size();i++){
            ans=max(ans,sp[i]-sp[i-1]-1);
        }
        
        return ans;
    }
};