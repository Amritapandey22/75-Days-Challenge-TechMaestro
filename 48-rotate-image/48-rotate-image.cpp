class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        //transpose+reverse
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(i<=j){
                    swap(m[i][j],m[j][i]);
                }
            }
        }
        
        int l=0;
        int r=m.size()-1;
        while(l<r){
            for(int i=0;i<m.size();i++){
                swap(m[i][l],m[i][r]);
            }
            l++;
            r--;
        }
    }
};