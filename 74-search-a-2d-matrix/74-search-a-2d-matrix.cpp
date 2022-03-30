class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int trg) {
        int n=mt.size(),m=mt[0].size();
        
        int si=0,ei=n*m-1;
        while(si<=ei){
            int mid=(si+ei)/2,r=mid/m,c=mid%m;
            
            if(mt[r][c]==trg)return true;
            
            else if(mt[r][c]<trg)si=mid+1;
            else ei=mid-1;
        }
        
        return false;
    }
};