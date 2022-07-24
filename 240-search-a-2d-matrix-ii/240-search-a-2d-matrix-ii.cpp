class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int trg) {
       int n=mat.size(),m=mat[0].size();
        
        int r=0,c=m-1;
        while(r<n and c>=0){
            if(mat[r][c]==trg)return true;
            else if(mat[r][c]<trg)r++;
            else c--;
        }
        
        return false;
        
    }
};