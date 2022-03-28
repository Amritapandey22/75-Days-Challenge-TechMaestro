class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int total=n*n;
        int minr=0;
        int minc=0;
        int maxr=n-1;
        int maxc=n-1;
        int val=1;
        
        while(minr <= maxr and minc <= maxc and total){
            for(int i=minc;i<=maxc and total;i++){
                ans[minr][i]=val++;
                total--;
            }
            minr++;
            
            for(int i=minr;i<=maxr and total;i++){
                ans[i][maxc]=val++;
                total--;
            }
            maxc--;
            
            for(int i=maxc;i>=minc and total;i--){
                ans[maxr][i]=val++;
                total--;
            }
            maxr--;
            for(int i=maxr;i>=minr and total;i--){
                ans[i][minc]=val++;
                total--;
            }
            minc++;
        }
        return ans;
    }
};